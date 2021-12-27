#pragma once
#pragma warning(disable : 4716)
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <locale> 
#include <fstream>
#include <time.h>
#include <string>
#include <cstring>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <thread>
#include "MyForm1.h"
using namespace std;
vector<string> v1(10);
HANDLE out;
HANDLE hSemaphore;
HANDLE hThread;
DWORD WINAPI Sort(LPVOID)
{
	string bufic = "";
	string buffer = "";
	vector<string> v1(10);
	string path = "info.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		v1.clear();
		getline(fs, buffer);
		for (int i = 0; i < 10; i++)
		{
			v1.push_back(buffer.substr(i * 10, 10));
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << v1[i] << endl;
	};
	sort(v1.begin(), v1.end(), greater<>());
	for (int i = 0; i < 10; i++)
	{
		cout << v1[i] << endl;
		bufic += v1[i];
		bufic += '\n';
	}
	WriteFile(out, bufic.c_str(), 110, NULL, NULL);
	ReleaseSemaphore(hSemaphore, 1, NULL);
	
	return 0;
}
namespace Trynumber1WINDOW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			timer1->Start();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button2;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(57, 89);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(952, 56);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(503, 27);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Студент: Панкова Арина Сергеевна Группа: 500";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(57, 528);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(247, 89);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Вывести исходные данные";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(52, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(202, 27);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Исходные данные:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(52, 153);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 27);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Вектора:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(134, 191);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 27);
			this->label4->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(705, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 27);
			this->label5->TabIndex = 6;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(57, 184);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(952, 313);
			this->textBox2->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(714, 128);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 17);
			this->label6->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(771, 528);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(238, 90);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Вывести вектора";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1104, 630);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
		String^ filename;
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ NewForm = gcnew MyForm1();
		this->Hide();
		NewForm->ShowDialog();
		this->Show();
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		setlocale(LC_ALL, "Russian");
		try
		{
			filename = "info.txt";
			System::Text::Encoding^ Code = System::Text::Encoding::GetEncoding(1251);
			IO::StreamReader^ Reader = gcnew IO::StreamReader(filename, Code);
			textBox1->Text = Reader->ReadToEnd();
			Reader->Close();
		}
		catch (IO::FileNotFoundException^ Situation)
		{
			MessageBox::Show(Situation->Message + "\nФайла не существует",
				"Ошибка", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation);
		}
		catch (Exception^ Situation)
		{
			MessageBox::Show(Situation->Message, "Ошибка",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		DateTime dateTime = DateTime::Now;
		this->label5->Text = dateTime.ToString();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	out = CreateFile(L"st.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (out == INVALID_HANDLE_VALUE)
		label6->Text = "Файл не создан ";
	else {
		hSemaphore = CreateSemaphore(NULL, 0, 10, NULL);
		hThread = CreateThread(NULL, 0, Sort, NULL, 0, NULL);
		WaitForSingleObject(hSemaphore, INFINITE);
	}

	CloseHandle(out);

	try
	{
		filename = "itog.txt";
		System::Text::Encoding^ Code = System::Text::Encoding::GetEncoding(1251);
		cli::array <String^>^ MsString = IO::File::ReadAllLines("itog.txt", Code);
		textBox2->Lines = MsString;
	}
	catch (IO::FileNotFoundException^ Situation)
	{
		MessageBox::Show(Situation->Message + "\nНет такого файла",
			"Ошибка", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation);
	}
	catch (Exception^ Situation)
	{
		MessageBox::Show(Situation->Message, "Ошибка",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}
};
}
