#pragma warning(disable: 4100)

#include "MyComboBox.h"

System::Void FFXEditor::MyComboBox::myDrawItem( System::Object ^sender , DrawItemEventArgs ^e )
{
	if ( e->Index < 0
		|| e->Index >= Items->Count )
        return;
	
	Color color = SystemColors::ControlText;
	Rectangle rec = e->Bounds;
	if ( (e->State & DrawItemState::Selected) == DrawItemState::Selected
		&& (e->State & DrawItemState::ComboBoxEdit) != DrawItemState::ComboBoxEdit )
    {
		e->Graphics->FillRectangle(gcnew SolidBrush(SystemColors::Highlight), rec);
		color = Color::White;
    }else
	{
		e->Graphics->FillRectangle(gcnew SolidBrush(Color::White), rec);
		color = SystemColors::ControlText;
	}
	
	SolidBrush ^brush = gcnew SolidBrush(color);
	e->Graphics->DrawString (Items[e->Index]->ToString(), e->Font, brush, rec);
}
