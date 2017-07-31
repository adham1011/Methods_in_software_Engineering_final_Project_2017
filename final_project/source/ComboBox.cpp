#include "stdafx.h"
#include "ComboBox.h"
#include "Button.h"
#include <string.h>

wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	wstring r(buf);
	delete[] buf;
	return r;
}


ComboBox::ComboBox(int width, vector<string> entries) {
	this->_entries = entries;
	this->_width = width;
	int size = 0;
	size = entries.size();
	wstring stemp;
	Panel box(5, 10);
	//Button* list=new Button(size);
	Button display(4);
	display.setBorder(BorderType::Single);
	display.setText(L"none");
	box.AddControl(display, 0, 0);

	Panel choice(5, 10);
	//turn choice visability off
	Button list(4);
	list.setBorder(BorderType::Single);
	for (int i = 0; i < size; i++) {
		stemp = s2ws(entries[i]);
		list.setText(stemp);
		//list[i].setTop(this->_top);
		//list[i].setLeft(this->_left + _width + 1);
		//plus.addListener(listener);
		choice.AddControl(list, i*width, 0);

	}
	box.AddControl(list,width, 0);

}

size_t ComboBox::GetSelectedIndex() {
	return _index;

}

void ComboBox::SetSelectedIndex(size_t index) {
	this->_index = index;
	//chsnge themain to 
	//wstring stemp;
	//		stemp = s2ws(entries[i]);
	//xxxxxx.setText(stemp);

}

void ComboBox::clickonmain(size_t index) {

	//if visabilty is on turn off otherwise turn on

}

void ComboBox::clickonchoice(size_t index) {
	//turn visabilty off

	SetSelectedIndex(index);
}