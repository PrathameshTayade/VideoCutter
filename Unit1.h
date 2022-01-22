//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TVideoCutter : public TForm
{
__published:	// IDE-managed Components
	TButton *run;
	TEdit *from;
	TEdit *to;
	TEdit *outputFName;
	TEdit *OutputPath;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *Add;
	TListBox *ListBox;
	TLabel *Total;
	TLabel *count;
	TEdit *ipfile;
	TButton *Import;
	void __fastcall AddClick(TObject *Sender);
	void __fastcall ListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall runClick(TObject *Sender);
	void __fastcall ImportClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TVideoCutter(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVideoCutter *VideoCutter;
//---------------------------------------------------------------------------
#endif
