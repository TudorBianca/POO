#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ input_cnp;
	protected:

	private: System::Windows::Forms::TextBox^ afisaj_cnp;
	private: System::Windows::Forms::Button^ calculeaza_cnp;
	private: System::Windows::Forms::Button^ sterge;

	protected:



	protected:






	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->input_cnp = (gcnew System::Windows::Forms::TextBox());
			this->afisaj_cnp = (gcnew System::Windows::Forms::TextBox());
			this->calculeaza_cnp = (gcnew System::Windows::Forms::Button());
			this->sterge = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// input_cnp
			// 
			this->input_cnp->Cursor = System::Windows::Forms::Cursors::No;
			this->input_cnp->Location = System::Drawing::Point(22, 35);
			this->input_cnp->Name = L"input_cnp";
			this->input_cnp->Size = System::Drawing::Size(215, 22);
			this->input_cnp->TabIndex = 0;
			// 
			// afisaj_cnp
			// 
			this->afisaj_cnp->Location = System::Drawing::Point(22, 181);
			this->afisaj_cnp->Name = L"afisaj_cnp";
			this->afisaj_cnp->Size = System::Drawing::Size(215, 22);
			this->afisaj_cnp->TabIndex = 1;
			// 
			// calculeaza_cnp
			// 
			this->calculeaza_cnp->Location = System::Drawing::Point(22, 106);
			this->calculeaza_cnp->Name = L"calculeaza_cnp";
			this->calculeaza_cnp->Size = System::Drawing::Size(102, 33);
			this->calculeaza_cnp->TabIndex = 2;
			this->calculeaza_cnp->Text = L"Calculeaza";
			this->calculeaza_cnp->UseMnemonic = false;
			this->calculeaza_cnp->UseVisualStyleBackColor = true;
			this->calculeaza_cnp->Click += gcnew System::EventHandler(this, &Form1::calculeaza_cnp_Click);
			// 
			// sterge
			// 
			this->sterge->Location = System::Drawing::Point(130, 106);
			this->sterge->Name = L"sterge";
			this->sterge->Size = System::Drawing::Size(107, 33);
			this->sterge->TabIndex = 3;
			this->sterge->Text = L"Sterge";
			this->sterge->UseVisualStyleBackColor = true;
			this->sterge->Click += gcnew System::EventHandler(this, &Form1::Sterge_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->sterge);
			this->Controls->Add(this->calculeaza_cnp);
			this->Controls->Add(this->afisaj_cnp);
			this->Controls->Add(this->input_cnp);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void sterge_Click(System::Object^ sender, System::EventArgs^ e)
	{
		input_cnp->Clear();
		afisaj_cnp->Clear();
	}
	private:System::Void calculeaza_cnp_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (input_cnp->Text->Length == 0)
		{
			MessageBox::Show("Introduceti CNP-ul!", "Eroare", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else
		{
			//Citip CNP-IL
			String^ cnp = input_cnp->Text;
			//Extragerea datelor din CNP
			//2800519016909
			int an = Int32::Parse(cnp->Substring(1, 2));
			int luna = Int32::Parse(cnp->Substring(3, 2));
			int zi = Int32::Parse(cnp->Substring(5, 2));
			//Calculam varsta
			DateTime azi = DateTime::Now;

			int century = 0;
			if (Int32::Parse(cnp->Substring(0, 1)) <= 2)
			{
				century = 1900;
			}
			else if (Int32::Parse(cnp->Substring(0, 1)) <= 4)
			{
				century = 1800;
			}
			else if (Int32::Parse(cnp->Substring(0, 1)) <= 6)

			{
				century = 2000;
			}
			else if (Int32::Parse(cnp->Substring(0, 1)) <= 8)
				{
					century = 1900;
				}
			int varsta = azi.Year - (century + an);
				//Afisam datele in afisaj_cnp
				afisaj_cnp->Text = "Data nasterii:" + zi.ToString() + "/" + luna.ToString() + "/" + an.ToString() + "\n" + "Varsta" + varsta.ToString();
		}
	}
	private: System::Void Sterge_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}