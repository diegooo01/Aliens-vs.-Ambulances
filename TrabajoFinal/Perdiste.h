#pragma once
//#include "Inicio2.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Perdiste
	/// </summary>
	public ref class Perdiste : public System::Windows::Forms::Form
	{
	public:
		Perdiste(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Perdiste()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Perdiste::typeid));
			this->SuspendLayout();
			// 
			// Perdiste
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(665, 506);
			this->Name = L"Perdiste";
			this->Text = L"Perdiste";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BtnReinicar_Click(System::Object^ sender, System::EventArgs^ e) {
		/*Juego^ JuegoReiniciado = gcnew Juego();
		JuegoReiniciado->ShowDialog();*/
	}
	private: System::Void BtnInicio_Click(System::Object^ sender, System::EventArgs^ e) {
		/*Inicio2^ MenuPrincipal = gcnew Inicio2();
		MenuPrincipal->ShowDialog();*/

	}
	};
}
