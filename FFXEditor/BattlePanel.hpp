#ifndef BATTLE_PANEL_HPP
#define BATTLE_PANEL_HPP

#include "MyPanel.hpp"
#include "ui_BattlePanel.h"

#include <vector>

using std::vector;

class BattleData;

class BattlePanel : public MyPanel
{
public:
	BattlePanel( QWidget *p );
	~BattlePanel( );
	
	virtual bool reloadData( int depth = 0 );
	virtual bool initData( );
	virtual bool checkData( int depth = 0 );
	virtual bool writeData( int depth = 0 );
	
	void unlock( );
	void lock( );
	
private:
	Ui::BattlePanel ui;
	vector<BattleData*> bData;
	bool locked;
	
	/*
private:
	/// <summary>
	/// Erforderliche Designervariable.
	/// </summary>
	System::ComponentModel::Container ^components;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  button2;
	bool locked;
	static array<BattleData^> ^bData;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Erforderliche Methode für die Designerunterstützung.
	/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
	/// </summary>
	void InitializeComponent(void)
	{
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(3, 3);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(75, 23);
		this->button1->TabIndex = 0;
		this->button1->Text = L"Get Data";
		this->button1->UseVisualStyleBackColor = true;
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(84, 3);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(75, 23);
		this->button2->TabIndex = 1;
		this->button2->Text = L"Save Data";
		this->button2->UseVisualStyleBackColor = true;
		// 
		// BattlePanel
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->Controls->Add(this->button2);
		this->Controls->Add(this->button1);
		this->Name = L"BattlePanel";
		this->Size = System::Drawing::Size(620, 410);
		this->ResumeLayout(false);
	}
#pragma endregion*/
};

#endif // BATTLE_PANEL_HPP
