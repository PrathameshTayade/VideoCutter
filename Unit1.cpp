//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include<iostream>
//#include<sys/wait.h>
#include "Unit1.h"
#include<vector>
#include<stdlib.h>
#include<cstdlib>
//#include<Windows.h>
#include<sys/types.h>
#include<process.h>
#include<processthreadsapi.h>
#include <strsafe.h>
#include "processthreadsapi.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TVideoCutter *VideoCutter;
//---------------------------------------------------------------------------
   using namespace std;
   String inputF = "";
class taskList
{
  private :
   String tfrom;
   String  tto;
   String outputFileName;
   String outputPath;

	  public :
   taskList(String f,String t, String fil, String p){

   tfrom = f;
   tto = t;
   outputFileName = fil;
   outputPath = p;

   }
	String getfrom()
	{
	return tfrom;
	}
		String getTO()
	{
	return tto;
	}
	String getoutputFileName()
	{
	return outputFileName;
	}
		String getoutputPath()
	{
	return outputPath;
	}

	void setFrom(String f)
	{
	  tfrom = f;
	}
		void setTto(String f)
	{
	  tto = f;
	}
		void setOutputFileName(String f)
	{
	  outputFileName = f;
	}
		void setoutputPath(String f)
	{
	  outputPath = f;
	}

}  ;
std::vector<taskList> tasks;
__fastcall TVideoCutter::TVideoCutter(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TVideoCutter::AddClick(TObject *Sender)
{        if(from->Text!= "" && to->Text!= "" && outputFName->Text!= "" && OutputPath->Text!= "") {
		 taskList t(from->Text,to->Text,outputFName->Text,OutputPath->Text);
		 String s =   from->Text + " to " + to->Text+  "; Name "+outputFName->Text+ "; Path " + OutputPath->Text;
		 ListBox->Items->Add(s);
		 tasks.push_back(t);
		   from->Text = "";
		   to->Text = "";
		   outputFName->Text  = "";
		   OutputPath->Text  = "";
		   count->Text = tasks.size();
}                                       }
//---------------------------------------------------------------------------

void __fastcall TVideoCutter::ListBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{    tasks.erase(tasks.begin() + Item->Index);
	 ListBox->Items->Delete(Item->Index);
     count->Text = tasks.size();
}
//---------------------------------------------------------------------------


void __fastcall TVideoCutter::runClick(TObject *Sender)
{ //ffmpeg -ss 00:01:00 -to 00:05:00 -i "F:\Deep learn\Coa\Intro and weightage analysis + intro + signed binary data representation(integer).mp4" -c copy "F:\Deep learn\Coa\Computer Organization and Architecture\name.mp4"
 if(tasks.size()>0) {
 String s = "";
	   for(int i=0; i< tasks.size();i++)
	   {

		 String tfrom = tasks[i].getfrom();
	String tto = tasks[i].getTO();

	String outputPath = tasks[i].getoutputPath();
	String outputFileName = tasks[i].getoutputFileName();

			 if(i!=3 && i!=0)
			  { s += String("&& ffmpeg -ss ") +
					tfrom  + " -to " + tto + " -i " + " \"" +inputF + "\""+" -c copy " + " \"" +outputPath + outputFileName+"\"";
				}
				else
				{
					s+= String("ffmpeg -ss ") +
					tfrom  + " -to " + tto + " -i " + " \"" +inputF + "\""+" -c copy " + " \"" +outputPath + outputFileName+"\"";
				}







	   }
	   _wsystem(s.c_str());
	   inputF = "";
	   }
}
//---------------------------------------------------------------------------


void __fastcall TVideoCutter::ImportClick(TObject *Sender)
{
	 if(ipfile->Text != "")
	 {
		inputF = ipfile->Text;
	 }
}
//---------------------------------------------------------------------------

