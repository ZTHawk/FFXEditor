#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace FFXEditor
{
	public ref class MyTableLayoutPanel : public TableLayoutPanel
	{
	public:
		MyTableLayoutPanel( )
		{
			__super::TableLayoutPanel();
			SetStyle(ControlStyles::AllPaintingInWmPaint
				| ControlStyles::UserPaint
				| ControlStyles::OptimizedDoubleBuffer, true);
		}
		
		void UpdateStyle( )
		{
			__super::UpdateStyles();
		}
	};
}
