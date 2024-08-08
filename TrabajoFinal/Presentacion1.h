#pragma once
#include "Inicio2.h"
#include "Instrucciones3.h"
#include "Creditos4.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Presentacion1
	/// </summary>
	public ref class Presentacion1 : public System::Windows::Forms::Form
	{
	public:
		Presentacion1(void)
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
		~Presentacion1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ BtnInicio;
	protected:
	private: System::Windows::Forms::Button^ BtnInstrucciones;
	private: System::Windows::Forms::Button^ BtnCreditos;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Presentacion1::typeid));
			this->BtnInicio = (gcnew System::Windows::Forms::Button());
			this->BtnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->BtnCreditos = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// BtnInicio
			// 
			this->BtnInicio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BtnInicio->Font = (gcnew System::Drawing::Font(L"Segoe Print", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnInicio->Location = System::Drawing::Point(383, 211);
			this->BtnInicio->Name = L"BtnInicio";
			this->BtnInicio->Size = System::Drawing::Size(187, 65);
			this->BtnInicio->TabIndex = 0;
			this->BtnInicio->Text = L"INICIO";
			this->BtnInicio->UseVisualStyleBackColor = false;
			this->BtnInicio->Click += gcnew System::EventHandler(this, &Presentacion1::BtnInicio_Click);
			// 
			// BtnInstrucciones
			// 
			this->BtnInstrucciones->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BtnInstrucciones->Font = (gcnew System::Drawing::Font(L"Segoe Print", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnInstrucciones->Location = System::Drawing::Point(383, 305);
			this->BtnInstrucciones->Name = L"BtnInstrucciones";
			this->BtnInstrucciones->Size = System::Drawing::Size(187, 65);
			this->BtnInstrucciones->TabIndex = 0;
			this->BtnInstrucciones->Text = L"INSTRUCCIONES";
			this->BtnInstrucciones->UseVisualStyleBackColor = false;
			this->BtnInstrucciones->Click += gcnew System::EventHandler(this, &Presentacion1::BtnInstrucciones_Click);
			// 
			// BtnCreditos
			// 
			this->BtnCreditos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BtnCreditos->Font = (gcnew System::Drawing::Font(L"Segoe Print", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnCreditos->Location = System::Drawing::Point(383, 411);
			this->BtnCreditos->Name = L"BtnCreditos";
			this->BtnCreditos->Size = System::Drawing::Size(187, 65);
			this->BtnCreditos->TabIndex = 0;
			this->BtnCreditos->Text = L"CREDITOS";
			this->BtnCreditos->UseVisualStyleBackColor = false;
			this->BtnCreditos->Click += gcnew System::EventHandler(this, &Presentacion1::BtnCreditos_Click);
			// 
			// Presentacion1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(649, 575);
			this->Controls->Add(this->BtnCreditos);
			this->Controls->Add(this->BtnInstrucciones);
			this->Controls->Add(this->BtnInicio);
			this->Name = L"Presentacion1";
			this->Text = L"Presentacion1";
			this->ResumeLayout(false);

		}
#pragma endregion
		//Inicio
	private: System::Void BtnInicio_Click(System::Object^ sender, System::EventArgs^ e) {
		Inicio2^ formularioInicio = gcnew Inicio2();
		formularioInicio->ShowDialog();
	}
		   //Instrucciones
	private: System::Void BtnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		Instrucciones3^ formularioInstrucciones = gcnew Instrucciones3();
		formularioInstrucciones->ShowDialog();
	}
		   //Creditos
	private: System::Void BtnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		Creditos4^ formularioCreditos = gcnew Creditos4();
		formularioCreditos->ShowDialog();
	}
	};
}
