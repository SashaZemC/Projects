// Training_Dialog_Panel.cpp : implementation file
//

#include "pch.h"
#include "Training_English_Words_MemoryDlg_V2.h"
#include "Training_English_Words_MemoryDlg_V2Dlg.h"
#include "Training_Dialog_Panel.h"
#include "SETTING_Menu_Dialog.h"
#include "ReadUserFileName.h"
#include "UserErrorDialog.h"
#include "afxdialogex.h"
#include <fstream>

using namespace std;
// Training_Dialog_Panel dialog

IMPLEMENT_DYNAMIC(Training_Dialog_Panel, CDialog)

Training_Dialog_Panel::Training_Dialog_Panel(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, LanguageMode(_T("English-Ukrainian"))
	, Word(_T(""))
	, Translation(_T(""))
	, E1(_T("All right"))
	, E2(_T(""))
{

}

Training_Dialog_Panel::~Training_Dialog_Panel()
{
}

void Training_Dialog_Panel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, LanguageMode);
	DDX_Text(pDX, IDC_EDIT2, Word);
	DDX_Text(pDX, IDC_EDIT1, Translation);
	DDX_Text(pDX, IDC_E1, E1);
	DDX_Text(pDX, IDC_E2, E2);
	srand((unsigned)time(NULL));
}


BEGIN_MESSAGE_MAP(Training_Dialog_Panel, CDialog)
	ON_COMMAND(ID_MENU_START, &Training_Dialog_Panel::OnMenuStart)
	ON_COMMAND(ID_MENU_STOP, &Training_Dialog_Panel::OnMenuStop)
	ON_COMMAND(ID_MENU_RESET, &Training_Dialog_Panel::OnMenuReset)
	ON_COMMAND(ID_MENU_SETTINGS, &Training_Dialog_Panel::OnMenuSettings)
	ON_COMMAND(ID_MENU_CHOOSEFILENAME, &Training_Dialog_Panel::OnMenuChoosefilename)
END_MESSAGE_MAP()


// Training_Dialog_Panel message handlers


BOOL Training_Dialog_Panel::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  Add extra initialization here
	setlocale(LC_ALL, "rus");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}




CString Training_Dialog_Panel::derivation_of_user_statistics(bool show_words_count, bool show_incorrect_words_count, int incorrect_words_counter, int translated_words_counter)
{
	if ((show_words_count) && (show_incorrect_words_count)) {
		z = " mistakes: ";
		t.Format(L"%i", incorrect_words_counter);
		z += t;
		z += "\n";
		z += " translated words: ";
		t.Format(L"%i", translated_words_counter);
		z += t;
	}
	else if (show_words_count) {
		z = " translated words: ";
		t.Format(L"%i", translated_words_counter);
		z += t;
	}
	else if (show_incorrect_words_count) {
		z = " mistakes: ";
		t.Format(L"%i", incorrect_words_counter);
		z += t;
	}

	return z;
}

CString Training_Dialog_Panel::Translate_checking()
{
	t = WordPairsArray[word_pair_counter];// word_pair_counter begins from 1
	ms = "";
	UpdateData(true);
	translate = Translation;
	UpdateData(false);

	Cutting_Word_From_String_number();

	if (translate == translate_check)  //comparison
	{
		translated_words_counter++;
		ms = "Properly";
		if (repeat_word_with_mistake)fg2 = true;
	}
	else
	{
		incorrect_words_counter++;
		ms = "False, correct: ";
		ms += translate_check;
		if(repeat_word_with_mistake)fg2 = false;
	}
	translate_check.Empty();

	derivation_of_user_statistics(show_words_count, show_incorrect_words_count, incorrect_words_counter, translated_words_counter);

	UpdateData(true);
	E1 = ms;
	E2 = z;
	UpdateData(false);
	
	if (!fg2) 
	{
		Sleep(1500);
		UpdateData(true);
		E1 = "";
		UpdateData(false);
	}


	return ms;
}

CString Training_Dialog_Panel::Cutting_Word_From_String_number()
{
	bool fg = false;
	CString buffer1, buffer2;

	if (Language_Mode) //cutting translate_check
	{
		for (int j = 0; (j < t.GetLength()); j++) // cut second word from string
		{
			if ((fg == false))buff[0] = t.GetAt(j);
			if (fg == true)buffer1 += t[j];
			if (buff[0] == '|')fg = true;
		}
	}
	if (!Language_Mode)
	{
		for (int j = 0; (j < t.GetLength()); j++)// cut first word from string
		{
			if (fg == false)buff[0] = t.GetAt(j);
			if (buff[0] == '|')break;
			if (fg == false)buffer1 += t[j];

		}
	}
	translate_check = buffer1;

	fg = false;
	if (Language_Mode) //cutting word
	{
		for (int j = 0; (j < t.GetLength()); j++)// cut first word from string
		{
			if (fg == false)buff[0] = t.GetAt(j);
			if (buff[0] == '|')break;
			if (fg == false)buffer2 += t[j];
		}
	}
	if (!Language_Mode)
	{
		for (int j = 0; (j < t.GetLength()); j++) // cut second word from string
		{
			if ((fg == false))buff[0] = t.GetAt(j);
			if (fg == true)buffer2 += t[j];
			if (buff[0] == '|')fg = true;
		}
	}
	word = buffer2;

	return translate_check, word;
}

void Training_Dialog_Panel::OnMenuStart()
{
	// set up settings
	UpdateData(true);
	h = LanguageMode; 
	UpdateData(false);

	if (h == "English-Ukrainian")Language_Mode = true; //choosing language type english
	if (h == "Ukrainian-English")Language_Mode = false; //choosing language type ukrainian

	///////////////////// set up settings from SETTINGS menu
	CStdioFile setting_file;

	if (setting_file.Open(L"settings.txt", CFile::modeRead))
	{
		while (setting_file.ReadString(All_Lines))	//read all strings from file settings.txt
		{
			settingsArray.Add(All_Lines);
		}
		setting_file.Close();

		//set training settings from setting menu
		h = settingsArray[0]; // example of string: 0 1 0 0 1
		if (h[0] == '0')show_incorrect_words_count = false; //the first digit
		else show_incorrect_words_count = true;

		if (h[2] == '0')show_words_count = false;
		else show_words_count = true;

		if (h[4] == '0')endless_mode = false;
		else endless_mode = true;

		if (h[6] == '0')show_result_window = false;
		else show_result_window = true;

		if (h[8] == '0')repeat_word_with_mistake = false; //the last digit
		else repeat_word_with_mistake = true;
	}
	else
	{
		Training_Dialog_Panel errorObject;
		errorObject.error_type = 1;
		UserErrorDialog errorDialog;
		errorDialog.ReadErrorType(errorObject);
		errorDialog.DoModal();
	}

		//read information from user file 
		h = settingsArray[1];
		CStdioFile resource_file;
		if (resource_file.Open(h, CFile::modeRead))
		{
			while (resource_file.ReadString(All_Lines))
			{
				WordPairsArray.Add(All_Lines);
			}
			resource_file.Close();
		}
		else
		{
			Training_Dialog_Panel errorObject;
			errorObject.error_type = 2;
			UserErrorDialog errorDialog;
			errorDialog.ReadErrorType(errorObject);
			errorDialog.DoModal();
		}
		/////////////////////////
		translated_words_counter = 0;
		incorrect_words_counter = 0;

		t = WordPairsArray[word_pair_counter];
		Cutting_Word_From_String_number();

		derivation_of_user_statistics(show_words_count, show_incorrect_words_count, incorrect_words_counter, translated_words_counter);

		UpdateData(true);
		Word = word;
		h = LanguageMode;
		E2 = z;
		UpdateData(false);

		Start_button_on = true;
}

void Training_Dialog_Panel::OnMenuStop()
{
	// TODO: Add your command handler code here

	if (Start_button_on)Start_button_on = false;
	else if(!Start_button_on)Start_button_on = true;

}

void Training_Dialog_Panel::OnMenuReset()
{
	// TODO: Add your command handler code here
	word_pair_counter = 0;
	Start_button_on = false;
	File_control = true;
	settingsArray.RemoveAll();
	z = "";
	
	UpdateData(true);
	E2 = z;
	Word = "";
	E1 = "";
	Translation = "";
	UpdateData(false);
}

void Training_Dialog_Panel::OnMenuSettings()
{
	// TODO: Add your command handler code here
	SETTING_Menu_Dialog newDialog;
	newDialog.DoModal();

}

void Training_Dialog_Panel::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnOK();
	if (File_control)
	{
		if (Start_button_on)
		{
			Translate_checking();
			word = "";

			if (fg2)word_pair_counter++;
			t = WordPairsArray[word_pair_counter];
			if (!(t == "File is empty, you know all words in it"))
			{
				Cutting_Word_From_String_number(); //uses value t

				UpdateData(true);
				Word = word;
				Translation = "";
				UpdateData(false);
				word.Empty();
			}
			else
			{
				if (endless_mode)
				{
					word_pair_counter = 0;
					t = WordPairsArray[word_pair_counter];
					Cutting_Word_From_String_number();
					UpdateData(true);
					Word = word;
					UpdateData(false);
				}
				else
				{
					ms += "\n";
					ms += "File is empty, you know all words in it";
					UpdateData(true);
					E1 = ms;
					UpdateData(false);
					File_control = false;
				}

			}
		}
	}

}



void Training_Dialog_Panel::OnMenuChoosefilename()
{
	// TODO: Add your command handler code here
	ReadUserFileName newPanel;
	newPanel.DoModal();
}
