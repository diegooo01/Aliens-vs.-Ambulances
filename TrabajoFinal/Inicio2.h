#pragma once
#include "Juego.h"
#include "Juego2.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Inicio2
	/// </summary>
	public ref class Inicio2 : public System::Windows::Forms::Form
	{
	public:
		Inicio2(void)
		{
			InitializeComponent();



			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Inicio2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnFacil;
	protected:
	private: System::Windows::Forms::Button^ BtnDificil;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Inicio2::typeid));
			this->BtnFacil = (gcnew System::Windows::Forms::Button());
			this->BtnDificil = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// BtnFacil
			// 
			this->BtnFacil->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BtnFacil->Font = (gcnew System::Drawing::Font(L"Segoe Print", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnFacil->Location = System::Drawing::Point(69, 444);
			this->BtnFacil->Name = L"BtnFacil";
			this->BtnFacil->Size = System::Drawing::Size(193, 69);
			this->BtnFacil->TabIndex = 0;
			this->BtnFacil->Text = L"NIVEL 1";
			this->BtnFacil->UseVisualStyleBackColor = false;
			this->BtnFacil->Click += gcnew System::EventHandler(this, &Inicio2::BtnFacil_Click);
			// 
			// BtnDificil
			// 
			this->BtnDificil->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BtnDificil->Font = (gcnew System::Drawing::Font(L"Segoe Print", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnDificil->Location = System::Drawing::Point(395, 444);
			this->BtnDificil->Name = L"BtnDificil";
			this->BtnDificil->Size = System::Drawing::Size(193, 69);
			this->BtnDificil->TabIndex = 0;
			this->BtnDificil->Text = L"NIVEL 2";
			this->BtnDificil->UseVisualStyleBackColor = false;
			this->BtnDificil->Click += gcnew System::EventHandler(this, &Inicio2::BtnDificil_Click);
			// 
			// Inicio2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(655, 553);
			this->Controls->Add(this->BtnDificil);
			this->Controls->Add(this->BtnFacil);
			this->Name = L"Inicio2";
			this->Text = L"Inicio2";
			this->Load += gcnew System::EventHandler(this, &Inicio2::Inicio2_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
			//Nivel 1
	private: System::Void BtnFacil_Click(System::Object^ sender, System::EventArgs^ e) {
		Juego^ Nivel1 = gcnew Juego();
		Nivel1->ShowDialog();
	}
		   //Nivel 2
	private: System::Void BtnDificil_Click(System::Object^ sender, System::EventArgs^ e) {
		Juego2^ Nivel2 = gcnew Juego2();
		Nivel2->ShowDialog();
	}
	private: System::Void Inicio2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
