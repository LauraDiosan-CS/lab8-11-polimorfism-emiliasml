#include "UI.h"


int UI::login(){
	string user, pass;
	u.setUserName(user);
	u.setPassword(pass);
	cout << "Username: ";
	cin >> user;
	cout << endl << "Password:";
	cin >> pass;
	return s.login(user, pass);
}

void UI::logout(){
	s.logout(u.getUserName(), u.getPassword());
}

void UI::add(){
	string op;
	cout << "Add:" << endl << "   1.Phone" << endl << "   2.Drone";
	cin >> op;
	if (op == string("1")) {

	}

}

void UI::del()
{
}

//void UI::find() {
//	string producer;
//	cout << " Give the producer:";
//	cin >> producer;
//	vector<Series*> vect = s.findProducer(producer);
//	for (int i = 0; i < vect.size; i++)
//		cout << vect[i]->toString() << endl;
//}

//void UI::showAll(){
//	for (int i = 0; i < s.getSize(); i++)
//		cout << s.getAllSeries[i]) << endl;
//}

void UI::showMenu() {
	bool val = false;
	int rez = login();
	if (rez != -1) {
		while (!val) {
			cout << endl << "1. Add a product";
			cout << endl << "2. Show all the products";
			cout << endl << "3. Delete a product";
			cout << endl << "4. Search products by producer's name";
			cout << endl << "5. Logout";
			int opt;
			cout << "----Option: " << endl;
			cin >> opt;
			switch (opt) {
			//case 4: {find(); break; }
			//case 2: {showAll(); break; }
			case 5: {logout(); val = false; }
			}
		}
	}
	else cout << endl << "Try again!";
}
