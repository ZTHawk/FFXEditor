#pragma once

using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace FFXEditor
{
	public ref class MyComboBox : public System::Windows::Forms::ComboBox
	{
	public:
		MyComboBox( )
		{
			__super::ComboBox();
			DrawItem += gcnew DrawItemEventHandler(this, &MyComboBox::myDrawItem);
		};

	private:
		System::Void myDrawItem( System::Object ^sender , DrawItemEventArgs ^e );
	};
}