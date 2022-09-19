#pragma once
extern "C"{
	__declspec(dllexport)
		void hello();
	__declspec(dllexport)
		int createMessageBox(LPCWSTR Ltitle, LPCWSTR Ldesc, int icon);
	__declspec(dllexport)
		void createWindow(int x, int y, int width, int height, int flag);
}
int createMessageBox(LPCWSTR Ltitle, LPCWSTR Ldesc, int icon);