#pragma once
#include "Controladora.h"
#include "File.h"
#include "Perdiste.h"
#include "Ganaste.h"

using namespace std;

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Juego2
	/// </summary>
	public ref class Juego2 : public System::Windows::Forms::Form
	{
	public:
		Juego2(void)
		{
			InitializeComponent();
			srand(time(NULL));

			//MUSICA:

			MusicaEpica->PlayLooping();

			//Nivel Facil

			n1 = 5 + rand() % (8 - 5); //Aliens, medicamentos
			n2 = 3 + rand() % (5 - 3); //Aliados
			cora = 3;

			//

			file = new File();

			file->ReadData();


			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);

			bmpAmbulancia = gcnew Bitmap("cars.png");
			bmpAlien1 = gcnew Bitmap("alien1.png");
			bmpAlien2 = gcnew Bitmap("alien2.png");
			bmpMecanico = gcnew Bitmap("mecanico.png");
			bmpMedicamento = gcnew Bitmap("medicamento.png");
			bmpCorazon = gcnew Bitmap("corazon.png");
			bmpHospital = gcnew Bitmap("hospital.png");
			bmpMap = gcnew Bitmap("fondo.png");

			ambulancia = new Ambulancia(bmpAmbulancia->Width / 8, bmpAmbulancia->Height / 2, file->get_x(), file->get_y(), file->get_dx(), file->get_dy());
			hospital = new Hospital(bmpHospital->Width / 1, bmpHospital->Height / 1);
			controller = new Controladora(cora);
			controller->CrearAliens_uno(bmpAlien1->Width / 5, bmpAlien1->Height / 2, n1); //Alien gris
			controller->CrearAliens_dos(bmpAlien2->Width / 6, bmpAlien2->Height / 4, n1); //Alien Rojo
			controller->CrearMecanico(bmpMecanico->Width / 8, bmpMecanico->Height / 1, n2);
			controller->CrearMedicamentos(bmpMedicamento->Width / 9, bmpMedicamento->Height / 2, n1);
			controller->CrearCorazones(bmpCorazon->Width / 1, bmpCorazon->Height / 1, 0);

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego2()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		//Declaracion de variables:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpAmbulancia;
		Bitmap^ bmpAlien1;
		Bitmap^ bmpAlien2;
		Bitmap^ bmpMecanico;
		Bitmap^ bmpMedicamento;
		Bitmap^ bmpCorazon;
		Bitmap^ bmpHospital;

		Bitmap^ bmpMap;
		Ambulancia* ambulancia;
		Hospital* hospital;
		Controladora* controller;
		File* file;

		//Cantidades de los arreglos: 
		int n1;
		int n2;
		int cora;

		SoundPlayer^ MusicaEpica = gcnew SoundPlayer("MusicaEpica2.wav");

	private: System::Windows::Forms::Panel^ pnlCanvas;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblCorazon;
	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Método necesario para admitir el Diseñador. No se puede modificar
		   /// el contenido de este método con el editor de código.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Juego2::typeid));
			   this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			   this->lblCorazon = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlCanvas->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pnlCanvas
			   // 
			   this->pnlCanvas->Controls->Add(this->lblCorazon);
			   this->pnlCanvas->Location = System::Drawing::Point(4, 3);
			   this->pnlCanvas->Name = L"pnlCanvas";
			   this->pnlCanvas->Size = System::Drawing::Size(1219, 740);
			   this->pnlCanvas->TabIndex = 0;
			   // 
			   // lblCorazon
			   // 
			   this->lblCorazon->AutoSize = true;
			   this->lblCorazon->BackColor = System::Drawing::Color::Transparent;
			   this->lblCorazon->Font = (gcnew System::Drawing::Font(L"Dubai", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblCorazon->ForeColor = System::Drawing::Color::Black;
			   this->lblCorazon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lblCorazon.Image")));
			   this->lblCorazon->Location = System::Drawing::Point(68, 15);
			   this->lblCorazon->Name = L"lblCorazon";
			   this->lblCorazon->Size = System::Drawing::Size(0, 48);
			   this->lblCorazon->TabIndex = 0;
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &Juego2::timer1_Tick);
			   // 
			   // Juego2
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1219, 740);
			   this->Controls->Add(this->pnlCanvas);
			   this->Name = L"Juego2";
			   this->Text = L"Juego2";
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego2::Juego2_KeyDown);
			   this->pnlCanvas->ResumeLayout(false);
			   this->pnlCanvas->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);

		lblCorazon->Text = Convert::ToString(controller->get_corazones());

		//Colision
		controller->Collision(buffer->Graphics, ambulancia, hospital);

		if (controller->get_corazones() <= 0) {
			MusicaEpica->Stop();
			timer1->Enabled = false;  //Permite pausar todo
			Perdiste^ GameOver = gcnew Perdiste();
			GameOver->ShowDialog();
		}

		//Detecta si ganaste
		if (ambulancia->get_Rectangle().IntersectsWith(hospital->get_Rectangle())) {

			if (controller->get_medicinas() == n1) {
				MusicaEpica->Stop();
				//Formulario: GANASTE!
				timer1->Enabled = false;  //Permite pausar todo
				Ganaste^ YouWin = gcnew Ganaste();
				YouWin->ShowDialog();
			}

		}

		//Movimiento
		controller->Move_Everything(buffer->Graphics);

		//Dibujar
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 1.5, bmpMap->Height * 1.5);
		controller->Draw_Everything(buffer->Graphics, bmpAlien1, bmpAlien2, bmpMecanico, bmpMedicamento, bmpCorazon);
		ambulancia->Draw(buffer->Graphics, bmpAmbulancia);
		hospital->Draw(buffer->Graphics, bmpHospital);

		//Render
		buffer->Render(g);

	}

	private: System::Void Juego2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		switch (e->KeyCode) {
		case Keys::A:
			ambulancia->Move(buffer->Graphics, 'A'); break;
		case Keys::S:
			ambulancia->Move(buffer->Graphics, 'S'); break;
		case Keys::D:
			ambulancia->Move(buffer->Graphics, 'D'); break;
		case Keys::W:
			ambulancia->Move(buffer->Graphics, 'W'); break;

		}
	}
	};
}