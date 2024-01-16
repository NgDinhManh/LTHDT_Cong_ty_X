#include <bits/stdc++.h>
#include <Windows.h>

using namespace std;

// Tao file doc va ghi du lieu
ifstream file_office("Office_worker_input.txt", ios::in);
ifstream file_production("Production_worker_input.txt", ios::in);
ifstream file_move("Move_worker_input.txt", ios::in);
ofstream file_list("File_list_worker.txt", ios::out);
ofstream file_statistical("File_output_statistical.txt", ios::out);

// Doi mau chu xuat ra man hinh
void TextColor(int x){
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

void MENU(){
	TextColor(11);
	cout << "\t\t\t\t\t+---------------------------------+\n";
	cout << "\t\t\t\t\t|              MENU               |\n";
	cout << "\t\t\t\t\t+---------------------------------+\n";
	cout << "\t\t\t\t\t|  1. Tim kiem nhan vien.         |\n";
	cout << "\t\t\t\t\t|  2. Xem danh sach nhan vien.    |\n";
	cout << "\t\t\t\t\t|  3. Them nhan vien.             |\n";
	cout << "\t\t\t\t\t|  4. Xoa nhan vien.              |\n";
	cout << "\t\t\t\t\t|  5. Chinh sua thong tin.        |\n";
	cout << "\t\t\t\t\t|  6. Thong ke.                   |\n";
	cout << "\t\t\t\t\t|  0. Thoat.                      |\n";
	cout << "\t\t\t\t\t+---------------------------------+\n";
}

// Menu cac lop nhan vien
void MENU_company(){
	cout << "\n\t1. Nhan vien van phong.\n";
	cout << "\t2. Nhan vien san xuat.\n";
	cout << "\t3. Nhan vien chuyen di khoi cong ty.\n";
}

// Menu cac tieu chi thong ke
void MENU_statistical(){
	cout << "\t0. Thong ke nhan vien trong cong ty.\n";
	cout << "\t1. Thong ke theo gioi tinh.\n";
	cout << "\t2. Thong ke theo nam sinh.\n";
	cout << "\t3. Thong ke theo tien luong.\n";
	cout << "\t4. Thong ke theo van phong.\n";
	cout << "\t5. Thong ke theo ngay vao cong ty.\n";
	cout << "\t6. Thong ke theo ngay nghi.\n";
	cout << "\t7. Thong ke theo ngay nghi cong nhan nu.\n";
	cout << "\t8. Thong ke nhan vien chuyen di khoi cong ty.\n";
}

// Tieu de cua nhan vien van phong
void Header_office(){
	TextColor(7);
	cout << " _________________________________________________________________________________________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|                Que quan              | Ngay vao cong ty | Luong (dong) |     Van phong   |\n";
	cout << "|---------+---------------------------+--------------+---------+--------------------------------------+------------------+--------------+-----------------|\n";
}

void Footer_office(){
	cout << "|_________|___________________________|______________|_________|______________________________________|__________________|______________|_________________|\n";	
}

// Tieu de cua cong nhan san xuat
void Header_production(){
	TextColor(7);
	cout << " ____________________________________________________________________________________________________________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|                Que quan              | Ngay vao cong ty | Luong (dong) | Dinh muc sp (sp/thang) | Ngay nghi |\n";
	cout << "|---------+---------------------------+--------------+---------+--------------------------------------+------------------+--------------+------------------------+-----------|\n";
}

void Footer_production(){
	cout << "|_________|___________________________|______________|_________|______________________________________|__________________|______________|________________________|___________|\n";
}

// Tieu de cua nhan vien chuyen di khoi cong ty
void Header_move(){
	TextColor(7);
	cout << " _________________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|  Ngay chuyen di  |\n";
	cout << "|---------+---------------------------+--------------+---------+------------------|\n";
}

void Footer_move(){
	cout << "|_________|___________________________|______________|_________|__________________|\n";
}

// Lop Mydate xu ly ngay thang nam
class Mydate {
	public:
		int day, month, year;
		Mydate(){}
		friend istream& operator >> (istream& is, Mydate &mydate){
			is >> mydate.day >> mydate.month >> mydate.year;
			return is;
		}

		friend ostream& operator << (ostream& os, const Mydate &mydate){
			os << mydate.day << "/" << setw(2) << mydate.month << "/" << setw(4) << mydate.year;
			return os;
		}

		bool operator > (Mydate mydate){
			if(year > mydate.year) return true;
			else if(year < mydate.year) return false;

			if(month > mydate.month) return true;
			else if(month < mydate.month) return false;

			if(day > mydate.day) return true;
			else return false;
		}
};

// Lop Company_X quan ly nhan vien cong ty X
class Company_X {
	protected:
		string Employee_code; // Ma nhan vien
		string Full_name; // Ho va ten
		Mydate Birthday; // Ngay sinh
		string Sex; // Gioi tinh
		string Native_place; // Que quan
		Mydate Day_start; // Ngay vao lam
		int Salary; // Tien luong
	public:
		static int Total_employee;

		// Lay du lieu nhan vien
		string get_Employee_code(){
			return Employee_code;
		}
		string get_Full_name(){
			return Full_name;
		}
		Mydate get_Birthday(){
			return Birthday;
		}
		string get_Sex(){
			return Sex;
		}
		string get_Native_place(){
			return Native_place;
		}
		Mydate get_Day_start(){
			return Day_start;
		}
		int get_Salary(){
			return Salary;
		}

		// Thay doi du lieu nhan vien
		void set_Employee_code(string employee_code){
			Employee_code = employee_code;
		}
		void set_Full_name(string full_name){
			Full_name = full_name;
		}
		void set_Birthday(Mydate birthday){
			Birthday = birthday;
		}
		void set_Sex(string sex){
			Sex = sex;
		}
		void set_Native_place(string native_place){
			Native_place = native_place;
		}
		void set_Day_start(Mydate day_start){
			Day_start = day_start;
		}
		void set_Salary(int salary){
			Salary = salary;
		}

		Company_X(){}
		void input(){
			cout << "Nhap ma nhan vien: ";
			getline(cin, Employee_code);
			cout << "Nhap Ten: ";
			getline(cin, Full_name);
			cout << "Nhap ngay sinh: ";
			cin >> Birthday;
			cin.ignore();
			cout << "Nhap gioi tinh: ";
			getline(cin, Sex);
			cout << "Nhap que quan: ";
			getline(cin, Native_place);
			cout << "Nhap ngay vao lam: ";
			cin >> Day_start;
			cout << "Nhap tien luong: ";
			cin >> Salary;
			cin.ignore();
			Total_employee++;
		}
		void output(){
			cout << "|" << setw(8) << Employee_code << " |";
			cout << setw(26) << Full_name << " |";
			cout << setw(4) << Birthday << "  |";
			cout << setw(6) << Sex << "   |";
			cout << setw(37) << Native_place << " |"; 
			cout << setw(6) << Day_start << "    |";
			cout << setw(13) << Salary << " |";
		}
		friend istream& operator >> (istream& is, Company_X &company_x){
			getline(is, company_x.Employee_code);
			getline(is, company_x.Full_name);
			is >> company_x.Birthday;
			is.ignore();
			getline(is, company_x.Sex);
			getline(is, company_x.Native_place);
			is >> company_x.Day_start;
			is >> company_x.Salary;
			is.ignore();
			company_x.Total_employee++;
			return is;
		}
		friend ostream& operator << (ostream& os, const Company_X &company_x){
			os << "|" << setw(8) << company_x.Employee_code << " |";
			os << setw(26) << company_x.Full_name << " |";
			os << setw(4) << company_x.Birthday << "  |";
			os << setw(6) << company_x.Sex << "   |";
			os << setw(37) << company_x.Native_place << " |"; 
			os << setw(6) << company_x.Day_start << "    |";
			os << setw(13) << company_x.Salary << " |" << endl;
			return os;
		}
		bool operator > (const Company_X company_x){
			string name1, name2;
			for(int i = Full_name.length() - 1; ; i--){
				char tmp_char = Full_name[i];
				name1 += tmp_char;
				if(Full_name[i-1] == ' '){
					break;
				}
			}
			for(int i = company_x.Full_name.length() - 1; ; i--){
				char tmp_char = company_x.Full_name[i];
				name2 += tmp_char;
				if(company_x.Full_name[i-1] == ' '){
					break;
				}
			}
			reverse(name1.begin(), name1.end()); // đảo ngược chuỗi
			reverse(name2.begin(), name2.end()); // đảo ngược chuỗi
			return name1 > name2;
		}
};

int Company_X::Total_employee = 0;

// Lop Move_worker quan ly nhan vien chuyen di khoi cong ty
class Move_worker : public Company_X {
	protected:
		Mydate Day_leave;
	public:
		Move_worker(){}
		// Lay du lieu nhan vien chuyen di khoi cong ty
		Mydate get_Day_leave(){
			return Day_leave;
		}

		// Thay doi du lieu chuyen di khoi cong ty
		void set_Day_leave(Mydate day_leave){
			Day_leave = day_leave;
		}

		void input(){
			getline(cin, Employee_code);
			getline(cin, Full_name);
			cin >> Birthday;
			cin.ignore();
			getline(cin, Sex);
			cin >> Day_leave;
			cin.ignore();
		}
		void output(){
			cout << "|" << setw(8) << Employee_code << " |";
			cout << setw(26) << Full_name << " |";
			cout << setw(4) << Birthday << "  |";
			cout << setw(6) << Sex << "   |";
			cout << setw(6) << Day_leave << "    |" << endl;
		}
		friend istream& operator >> (istream& is, Move_worker &move_worker){
			getline(is, move_worker.Employee_code);
			getline(is, move_worker.Full_name);
			is >> move_worker.Birthday;
			is.ignore();
			getline(is, move_worker.Sex);
			is >> move_worker.Day_leave;
			is.ignore();
			return is;
		}
		friend ostream& operator << (ostream& os, const Move_worker &move_worker){
			os << "|" << setw(8) << move_worker.Employee_code << " |";
			os << setw(26) << move_worker.Full_name << " |";
			os << setw(4) << move_worker.Birthday << "  |";
			os << setw(6) << move_worker.Sex << "   |";
			os << setw(6) << move_worker.Day_leave << "    |" << endl;
			return os;
		}
		bool operator > (const Move_worker move_worker){
			string name1, name2;
			for(int i = Full_name.length() - 1; ; i--){
				char tmp_char = Full_name[i];
				name1 += tmp_char;
				if(Full_name[i-1] == ' '){
					break;
				}
			}
			for(int i = move_worker.Full_name.length() - 1; ; i--){
				char tmp_char = move_worker.Full_name[i];
				name2 += tmp_char;
				if(move_worker.Full_name[i-1] == ' '){
					break;
				}
			}
			reverse(name1.begin(), name1.end()); // đảo ngược chuỗi
			reverse(name2.begin(), name2.end()); // đảo ngược chuỗi
			return name1 > name2;
		}
		friend void Find(Move_worker *mov_work, int size, string worker_code, int &check);
		friend void Add_employee_move(Move_worker* &mov_work, int &size, Move_worker move_worker);
		friend void Change_file(Move_worker *mov_work, int size);
};
// Tim kiem nhan vien chuyen di khoi cong ty
void Find(Move_worker *mov_work, int size, string worker_code, int &check){
	TextColor(7);
	for(int i=0; i<size; i++){
		if(worker_code == mov_work[i].Employee_code){
			cout << "\n\tNhan vien chuyen di khoi cong ty.\n";
			Header_move();
			cout << mov_work[i];
			Footer_move();
			check = 1;
			return;
		}
	}
	check = 0;
}
// Xuat danh sach nhan vien chuyen di khoi cong ty ra man hinh
void List_move(Move_worker *mov_work, int size){
	TextColor(7);
	cout << "                      NHAN VIEN CHUYEN DI KHOI CONG TY\n";
	cout << "Tong co " << size << " nhan vien.\n";
	Header_move();
	for(int i=0; i<size; i++){
		cout << mov_work[i];
	}
	Footer_move();
}
// Them nhan vien chuyen di khoi cong ty
void Add_employee_move(Move_worker* &mov_work, int &size, Move_worker move_worker){
	if(move_worker.Employee_code == ""){
		return;
	}
	int new_size = size + 1;
	Move_worker *_mov_work = new Move_worker[new_size];
	for(int i=0; i<size; i++){
		_mov_work[i] = mov_work[i];
	}

	// Luu thong tin doi tuong xoa
	_mov_work[new_size-1] = move_worker;

	delete[] mov_work;
	mov_work = _mov_work;
	size = new_size;
}
// Sua file doc du lieu
void Change_file(Move_worker *mov_work, int size){
	ofstream file_change("Move_worker_input.txt", ios::out);
	file_change << size << endl;
	for(int i=0; i<size; i++){
		file_change << mov_work[i].Employee_code << endl;
		file_change << mov_work[i].Full_name << endl;
		file_change << mov_work[i].Birthday.day << " " << mov_work[i].Birthday.month << " " << mov_work[i].Birthday.year << endl;
		file_change << mov_work[i].Sex << endl;
		file_change << mov_work[i].Day_leave.day << " " << mov_work[i].Day_leave.month << " " << mov_work[i].Day_leave.year << endl;
	}
	file_change.close();
}


// Lop Office_worker quan ly nhan vien van phong
class Office_worker : public Company_X {
	protected:
		string Office; // Van phong
	public:
		Office_worker(){}
		// Lay du lieu nhan vien van phong
		string get_Office(){
			return Office;
		}

		// Thay doi du lieu nhan vien van phong
		void set_Office(string office){
			Office = office;
		}

		void input(){
			Company_X::input();
			cout << "Nhap van phong: ";
			getline(cin, Office);
		}
		void output(){
			Company_X::output();
			cout << setw(16) << Office << " |" << endl;
		}
		friend istream& operator >> (istream& is, Office_worker &office_worker){
			getline(is, office_worker.Employee_code);
			getline(is, office_worker.Full_name);
			is >> office_worker.Birthday;
			is.ignore();
			getline(is, office_worker.Sex);
			getline(is, office_worker.Native_place);
			is >> office_worker.Day_start;
			is >> office_worker.Salary;
			is.ignore();
			getline(is, office_worker.Office);
			office_worker.Total_employee++;
			return is;
		}
		friend ostream& operator << (ostream& os, const Office_worker &office_worker){
			os << "|" << setw(8) << office_worker.Employee_code << " |";
			os << setw(26) << office_worker.Full_name << " |";
			os << setw(4) << office_worker.Birthday << "  |";
			os << setw(6) << office_worker.Sex << "   |";
			os << setw(37) << office_worker.Native_place << " |"; 
			os << setw(6) << office_worker.Day_start << "    |";
			os << setw(13) << office_worker.Salary << " |";
			os << setw(16) << office_worker.Office << " |" << endl;
			return os;
		}
		bool operator > (const Office_worker office_worker){
			string name1, name2;
			for(int i = Full_name.length() - 1; ; i--){
				char tmp_char = Full_name[i];
				name1 += tmp_char;
				if(Full_name[i-1] == ' '){
					break;
				}
			}
			for(int i = office_worker.Full_name.length() - 1; ; i--){
				char tmp_char = office_worker.Full_name[i];
				name2 += tmp_char;
				if(office_worker.Full_name[i-1] == ' '){
					break;
				}
			}
			reverse(name1.begin(), name1.end()); // đảo ngược chuỗi
			reverse(name2.begin(), name2.end()); // đảo ngược chuỗi
			return name1 > name2;
		}
		friend void Find(Office_worker *off_work, int size, string worker_code, int &check);
		friend void Add_employee_office(Office_worker* &off_work, int &size, int &mark_office_code);
		friend void Delete_employee_office(Office_worker* &off_work, int &size, Move_worker &move_worker);
		friend void Edit_employee_office(Office_worker* &off_work, int size);
		friend void Change_file(Office_worker *off_work, int size, int mark_office_code);
};
// Tim kiem nhan vien van phong
void Find(Office_worker *off_work, int size, string worker_code, int &check){
	TextColor(7);
	for(int i=0; i<size; i++){
		if(worker_code == off_work[i].Employee_code){
			cout << "\n\tNhan vien van phong.\n";
			Header_office();
			cout << off_work[i];
			Footer_office();
			check = 1;
			return;
		}
	}
	check = 0;
}
// Xuat danh sach nhan vien van phong ra man hinh
void List_office(Office_worker *off_work, int size){
	TextColor(7);
	cout << "\n                   	                         DANH SACH NHAN VIEN VAN PHONG\n";
	cout << "Tong co " << size << " nhan vien.\n";
	Header_office();
	for(int i=0; i<size; i++){
		cout << off_work[i];
	}
	Footer_office();
}
// Them nhan vien van phong
void Add_employee_office(Office_worker* &off_work, int &size, int &mark_office_code){
	int new_size = size + 1;
	mark_office_code++;
	Office_worker *_off_work = new Office_worker[new_size];
	for(int i=0; i<size; i++){
		_off_work[i] = off_work[i];
	}

	List_office(off_work, size);

	// Tao ma nhan vien
	_off_work[new_size-1].Employee_code = "";
	string tmp_code = to_string(mark_office_code);
	if(mark_office_code < 10){
		_off_work[new_size-1].Employee_code = "OFF00" + tmp_code;
	}
	else if(mark_office_code >=10 && mark_office_code < 100){
		_off_work[new_size-1].Employee_code = "OFF0" + tmp_code;
	}
	else {
		_off_work[new_size-1].Employee_code = "OFF" + tmp_code;
	}

	cout << "Nhap Ten: ";
	getline(cin, _off_work[new_size-1].Full_name);
	cout << "Nhap ngay sinh: ";
	cin >> _off_work[new_size-1].Birthday;
	cin.ignore();
	cout << "Nhap gioi tinh: ";
	getline(cin, _off_work[new_size-1].Sex);
	cout << "Nhap que quan: ";
	getline(cin, _off_work[new_size-1].Native_place);
	do{
		cout << "Nhap ngay vao lam: ";
		cin >> _off_work[new_size-1].Day_start;
		if(_off_work[new_size-1].Birthday > _off_work[new_size-1].Day_start){
			cout << "Ngay vao lam khong hop le. Vui long nhap lai!\n";
		}
	} while(_off_work[new_size-1].Birthday > _off_work[new_size-1].Day_start);
	cout << "Nhap tien luong: ";
	cin >> _off_work[new_size-1].Salary;
	cin.ignore();
	cout << "Nhap van phong: ";
	getline(cin, _off_work[new_size-1].Office);
	delete[] off_work;
	off_work = _off_work;
	size = new_size;
	Company_X::Total_employee++; // Cong them 1 nhan vien vao tong so nhan vien cua cong ty X
	cout << "***   Them thanh cong   ***\n";
}
// Xoa nhan vien van phong
void Delete_employee_office(Office_worker* &off_work, int &size, Move_worker &move_worker){
	int new_size = size - 1;
	Office_worker *_off_work = new Office_worker[new_size];

	List_office(off_work, size);

	int check;
	do{
		string employee_code;
		cout << "Nhap ma nhan vien xoa: ";
		getline(cin, employee_code);
		for(int i=0; i<size; i++){
			if(employee_code == off_work[i].Employee_code){
				// Lay thong tin doi tuong xoa
				move_worker.set_Employee_code(off_work[i].Employee_code);
				move_worker.set_Full_name(off_work[i].Full_name);
				move_worker.set_Birthday(off_work[i].Birthday);
				move_worker.set_Sex(off_work[i].Sex);
				Mydate day_leave;
				cout << "Nhap ngay chuyen di: ";
				cin >> day_leave;
				cin.ignore();
				move_worker.set_Day_leave(day_leave);
				for(int j=i; j<size-1; j++){
					off_work[j] = off_work[j+1];
				}

				check = 1;
				break;
			}else {
				check = 0;
			}
		}
		if(!check){
			string select2;
			cout << "Ma nhan vien khong dung.\n";
			cout << "Chon 0 de thoat / so bat ky de tiep tuc : ";
			getline(cin, select2);
			if(select2 == "0"){
				return;
			}
			cout << "Vui long nhap lai!\n";
		}
	} while(!check);

	for(int i=0; i<new_size; i++){
		_off_work[i] = off_work[i];
	}
	delete[] off_work;
	off_work = _off_work;
	size = new_size;
	Company_X::Total_employee--;
	cout << "***   Xoa thanh cong   ***\n";
}
// Chinh sua thong tin nhan vien
void Edit_employee_office(Office_worker* &off_work, int size){

	List_office(off_work, size);

	string employee_code;
	int check;
	do{
		check = 0;
		cout << "Nhap ma nhan vien chinh sua: ";
		getline(cin, employee_code);
		for(int i=0; i<size; i++){
			if(off_work[i].Employee_code == employee_code){
				check = 1;
				cout << "Chinh sua thong tin:\n";
				cout << "Nhap Ten: ";
				getline(cin, off_work[i].Full_name);
				cout << "Nhap ngay sinh: ";
				cin >> off_work[i].Birthday;
				cin.ignore();
				cout << "Nhap gioi tinh: ";
				getline(cin, off_work[i].Sex);
				cout << "Nhap que quan: ";
				getline(cin, off_work[i].Native_place);
				do{
					cout << "Nhap ngay vao lam: ";
					cin >> off_work[i].Day_start;
					if(off_work[i].Birthday > off_work[i].Day_start){
						cout << "Ngay vao lam khong hop le. Vui long nhap lai!\n";
					}
				} while(off_work[i].Birthday > off_work[i].Day_start);
				cout << "Nhap tien luong: ";
				cin >> off_work[i].Salary;
				cin.ignore();
				cout << "Nhap van phong: ";
				getline(cin, off_work[i].Office);
				cout << "***    Chinh sua thanh cong   ***\n";
			}
		}
		if(!check){
			string select2;
			cout << "Ma nhan vien khong dung.\n";
			cout << "Chon 0 de thoat / so bat ky de tiep tuc : ";
			getline(cin, select2);
			if(select2 == "0"){
				return;
			}
			cout << "Vui long nhap lai!\n";
		}
	} while(!check);
}
// Sua file doc du lieu nhan vien van phong
void Change_file(Office_worker *off_work, int size, int mark_office_code){
	ofstream file_change("Office_worker_input.txt", ios::out);
	file_change << mark_office_code << endl;
	file_change << size << endl;
	for(int i=0; i<size; i++){
		file_change << off_work[i].Employee_code << endl;
		file_change << off_work[i].Full_name << endl;
		file_change << off_work[i].Birthday.day << " " << off_work[i].Birthday.month << " " << off_work[i].Birthday.year << endl;
		file_change << off_work[i].Sex << endl;
		file_change << off_work[i].Native_place << endl; 
		file_change << off_work[i].Day_start.day << " " << off_work[i].Day_start.month << " " << off_work[i].Day_start.year << endl;
		file_change << off_work[i].Salary << endl;
		file_change << off_work[i].Office << endl;
	}
	file_change.close();
}


// Lop Production_worker quan ly cong nhan san xuat
class Production_worker : public Company_X {
	protected:
		int Product_norms; // Dinh muc san pham (san pham/ thang)
		string Day_off; // Ngay nghi trong tuan
	public:
		// Lay du lieu cong nhan san xuat
		int get_Product_norms(){
			return Product_norms;
		}
		string get_Day_off(){
			return Day_off;
		}

		// Thay doi du lieu cong nhan san xuat
		void get_Product_norms(int product_norms){
			Product_norms = product_norms;
		}
		void get_Day_off(string day_off){
			Day_off = day_off;
		}

		Production_worker(){}
		void input(){
			Company_X::input();
			cout << "Nhap dinh muc san pham: ";
			cin >> Product_norms;
			cin.ignore();
			cout << "Nhap ngay nghi: ";
			getline(cin, Day_off);
		}
		void output(){
			Company_X::output();
			cout << setw(23) << Product_norms << " |";
			cout << setw(10) << Day_off << " |" << endl;
		}
		friend istream& operator >> (istream& is, Production_worker &production_worker){
			getline(is, production_worker.Employee_code);
			getline(is, production_worker.Full_name);
			is >> production_worker.Birthday;
			is.ignore();
			getline(is, production_worker.Sex);
			getline(is, production_worker.Native_place);
			is >> production_worker.Day_start;
			is >> production_worker.Salary;
			is >> production_worker.Product_norms;
			is.ignore();
			getline(is, production_worker.Day_off);
			production_worker.Total_employee++;
			return is;
		}
		friend ostream& operator << (ostream& os, const Production_worker &production_worker){
			os << "|" << setw(8) << production_worker.Employee_code << " |";
			os << setw(26) << production_worker.Full_name << " |";
			os << setw(4) << production_worker.Birthday << "  |";
			os << setw(6) << production_worker.Sex << "   |";
			os << setw(37) << production_worker.Native_place << " |"; 
			os << setw(6) << production_worker.Day_start << "    |";
			os << setw(13) << production_worker.Salary << " |";
			os << setw(23) << production_worker.Product_norms << " |";
			os << setw(10) << production_worker.Day_off << " |" << endl;
			return os;
		}
		bool operator > (const Production_worker production_worker){
			string name1, name2;
			for(int i = Full_name.length() - 1; ; i--){
				char tmp_char = Full_name[i];
				name1 += tmp_char;
				if(Full_name[i-1] == ' '){
					break;
				}
			}
			for(int i = production_worker.Full_name.length() - 1; ; i--){
				char tmp_char = production_worker.Full_name[i];
				name2 += tmp_char;
				if(production_worker.Full_name[i-1] == ' '){
					break;
				}
			}
			reverse(name1.begin(), name1.end()); // đảo ngược chuỗi
			reverse(name2.begin(), name2.end()); // đảo ngược chuỗi
			return name1 > name2;
		}
		friend void Find(Production_worker *pro_work, int size, string worker_code, int &check);
		friend void Add_employee_production(Production_worker* &pro_work, int &size, int &mark_production_code);
		friend void Delete_employee_production(Production_worker* &pro_work, int &size, Move_worker &move_worker);
		friend void Edit_employee_production(Production_worker* &pro_work, int size);
		friend void Change_file(Production_worker *pro_work, int size,  int mark_production_code);
};
// Tim kiem cong nhan san xuat
void Find(Production_worker *pro_work, int size, string worker_code, int &check){
	TextColor(7);
	for(int i=0; i<size; i++){
		if(worker_code == pro_work[i].Employee_code){
			cout << "\n\tCong nhan san xuat.\n";
			Header_production();
			cout << pro_work[i];
			Footer_production();
			check = 1;
			return;
		}
	}
	check = 0;
}
// Xuat danh sach cong nhan san xuat ra man hinh
void List_production(Production_worker *pro_work, int size){
	TextColor(7);
	cout << "\n                   	                         DANH SACH CONG NHAN SAN XUAT\n";
	cout << "Tong co " << size << " nhan vien.\n";
	Header_production();
	for(int i=0; i<size; i++){
		cout << pro_work[i];
	}
	Footer_production();
}
// Them cong nhan san xuat
void Add_employee_production(Production_worker* &pro_work, int &size, int &mark_production_code){
	int new_size = size + 1;
	mark_production_code++;
	Production_worker *_pro_work = new Production_worker[new_size];
	for(int i=0; i<size; i++){
		_pro_work[i] = pro_work[i];
	}

	List_production(pro_work, size);

	// Tao ma nhan vien
	_pro_work[new_size-1].Employee_code = "";
	string tmp_code = to_string(mark_production_code);
	if(mark_production_code < 10){
		_pro_work[new_size-1].Employee_code = "PRO00" + tmp_code;
	}
	else if(mark_production_code >=10 && mark_production_code < 100){
		_pro_work[new_size-1].Employee_code = "PRO0" + tmp_code;
	}
	else {
		_pro_work[new_size-1].Employee_code = "PRO" + tmp_code;
	}

	cout << "Nhap Ten: ";
	getline(cin, _pro_work[new_size-1].Full_name);
	cout << "Nhap ngay sinh: ";
	cin >> _pro_work[new_size-1].Birthday;
	cin.ignore();
	cout << "Nhap gioi tinh: ";
	getline(cin, _pro_work[new_size-1].Sex);
	cout << "Nhap que quan: ";
	getline(cin, _pro_work[new_size-1].Native_place);
	do{
		cout << "Nhap ngay vao lam: ";
		cin >> _pro_work[new_size-1].Day_start;
		if(_pro_work[new_size-1].Birthday > _pro_work[new_size-1].Day_start){
			cout << "Ngay vao lam khong hop le. Vui long nhap lai!\n";
		}
	} while(_pro_work[new_size-1].Birthday > _pro_work[new_size-1].Day_start);
	cout << "Nhap tien luong: ";
	cin >> _pro_work[new_size-1].Salary;
	cin.ignore();
	cout << "Nhap dinh muc san pham: ";
	cin >> _pro_work[new_size-1].Product_norms;
	cin.ignore();
	if(_pro_work[new_size-1].Sex == "Nu" || _pro_work[new_size-1].Sex == "nu"){
		cout << "Nhap ngay nghi: ";
		getline(cin, _pro_work[new_size-1].Day_off);
	}else {
		_pro_work[new_size-1].Day_off = "Chu Nhat";
	}
	delete[] pro_work;
	pro_work = _pro_work;
	size = new_size;
	Company_X::Total_employee++; // Cong them 1 nhan vien vao tong so nhan vien cua cong ty X
	cout << "***   Them thanh cong   ***\n";
}
// Xoa cong nhan san xuat
void Delete_employee_production(Production_worker* &pro_work, int &size, Move_worker &move_worker){
	int new_size = size - 1;
	Production_worker *_pro_work = new Production_worker[new_size];

	List_production(pro_work, size);

	int check;
	do{
		string employee_code;
		cout << "Nhap ma cong nhan xoa: ";
		getline(cin, employee_code);
		for(int i=0; i<size; i++){
			if(employee_code == pro_work[i].Employee_code){
				// Lay thong tin doi tuong xoa
				move_worker.set_Employee_code(pro_work[i].Employee_code);
				move_worker.set_Full_name(pro_work[i].Full_name);
				move_worker.set_Birthday(pro_work[i].Birthday);
				move_worker.set_Sex(pro_work[i].Sex);
				Mydate day_leave;
				cout << "Nhap ngay chuyen di: ";
				cin >> day_leave;
				cin.ignore();
				move_worker.set_Day_leave(day_leave);
				for(int j=i; j<size-1; j++){
					pro_work[j] = pro_work[j+1];
				}

				check = 0;
				break;
			}else {
				check = 1;
			}
		}
		if(check){
			string select2;
			cout << "Ma cong nhan khong dung.\n";
			cout << "Chon 0 de thoat / so bat ky de tiep tuc : ";
			getline(cin, select2);
			if(select2 == "0"){
				return;
			}
			cout << "Vui long nhap lai!\n";
		}
	} while(check);

	for(int i=0; i<new_size; i++){
		_pro_work[i] = pro_work[i];
	}
	delete[] pro_work;
	pro_work = _pro_work;
	size = new_size;
	Company_X::Total_employee--;
	cout << "***   Xoa thanh cong   ***\n";
}
// Chinh sua thong tin cong nhan
void Edit_employee_production(Production_worker* &pro_work, int size){

	List_production(pro_work, size);

	string employee_code;
	int check;
	do{
		check = 0;
		cout << "Nhap ma nhan vien chinh sua: ";
		getline(cin, employee_code);
		for(int i=0; i<size; i++){
			if(pro_work[i].Employee_code == employee_code){
				check = 1;
				cout << "Chinh sua thong tin:\n";
				cout << "Nhap Ten: ";
				getline(cin, pro_work[i].Full_name);
				cout << "Nhap ngay sinh: ";
				cin >> pro_work[i].Birthday;
				cin.ignore();
				cout << "Nhap gioi tinh: ";
				getline(cin, pro_work[i].Sex);
				cout << "Nhap que quan: ";
				getline(cin, pro_work[i].Native_place);
				do{
					cout << "Nhap ngay vao lam: ";
					cin >> pro_work[i].Day_start;
					if(pro_work[i].Birthday > pro_work[i].Day_start){
						cout << "Ngay vao lam khong hop le. Vui long nhap lai!\n";
					}
				} while(pro_work[i].Birthday > pro_work[i].Day_start);
				cout << "Nhap tien luong: ";
				cin >> pro_work[i].Salary;
				cout << "Nhap dinh muc san pham: ";
				cin >> pro_work[i].Product_norms;
				cin.ignore();
				if(pro_work[i].Sex == "Nu" || pro_work[i].Sex == "nu"){
					cout << "Nhap ngay nghi: ";
					getline(cin, pro_work[i].Day_off);
				}
				cout << "***    Chinh sua thanh cong   ***\n";
			}
		}
		if(!check){
			string select2;
			cout << "Ma nhan vien khong dung.\n";
			cout << "Chon 0 de thoat / so bat ky de tiep tuc : ";
			getline(cin, select2);
			if(select2 == "0"){
				return;
			}
			cout << "Vui long nhap lai!\n";
		}
	} while(!check);
}
// Sua file doc du lieu cong nhan san xuat
void Change_file(Production_worker *pro_work, int size, int mark_production_code){
	ofstream file_change("Production_worker_input.txt", ios::out);
	file_change << mark_production_code << endl;
	file_change << size << endl;
	for(int i=0; i<size; i++){
		file_change << pro_work[i].Employee_code << endl;
		file_change << pro_work[i].Full_name << endl;
		file_change << pro_work[i].Birthday.day << " " << pro_work[i].Birthday.month << " " << pro_work[i].Birthday.year << endl;
		file_change << pro_work[i].Sex << endl;
		file_change << pro_work[i].Native_place << endl; 
		file_change << pro_work[i].Day_start.day << " " << pro_work[i].Day_start.month << " " << pro_work[i].Day_start.year << endl;
		file_change << pro_work[i].Salary << endl;
		file_change << pro_work[i].Product_norms << endl;
		file_change << pro_work[i].Day_off << endl;
	}
	file_change.close();
}


// Thong ke nhan vien trong cong ty
void Employee_statistical(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
		company_x[i].set_Native_place(off_work[i].get_Native_place());
		company_x[i].set_Day_start(off_work[i].get_Day_start());
		company_x[i].set_Salary(off_work[i].get_Salary());
	}

	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
		company_x[i].set_Native_place(pro_work[i - off_num].get_Native_place());
		company_x[i].set_Day_start(pro_work[i - off_num].get_Day_start());
		company_x[i].set_Salary(pro_work[i - off_num].get_Salary());
	}

	// Sap xep danh sach theo ten Alphabet
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j] > company_x[j+1]){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}

	TextColor(7);
	cout << "\n                   	                         DANH SACH NHAN VIEN CONG TY\n";
	cout << "Tong so: " << Company_X::Total_employee << " nhan vien" << endl;
	cout << " _______________________________________________________________________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|                Que quan              | Ngay vao cong ty | Luong (dong) |\n";
	cout << "|---------+---------------------------+--------------+---------+--------------------------------------+------------------+--------------|\n";
	for(int i=0; i<size; i++){
		cout << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
		cout << setw(26) << company_x[i].get_Full_name() << " |";
		Mydate tmp_birthday = company_x[i].get_Birthday();
		cout << setw(4) << tmp_birthday << "  |";
		cout << setw(6) << company_x[i].get_Sex() << "   |";
		cout << setw(37) << company_x[i].get_Native_place() << " |";
		Mydate tmp_day_start = company_x[i].get_Day_start();
		cout << setw(6) << tmp_day_start << "    |";
		cout << setw(13) << company_x[i].get_Salary() << " |" << endl;
	}
	cout << "|_________|___________________________|______________|_________|______________________________________|__________________|______________|\n";
}
// Thong ke theo gioi tinh
void Sex_statistical(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
	}

	// Sap xep theo nam sinh
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j].get_Birthday() > company_x[j+1].get_Birthday()){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}

	int Total_male = 0;
	for(int i=0; i<size; i++){
		if(company_x[i].get_Sex() == "Nam"){
			Total_male++;
		}
	}

	TextColor(7);
	cout << "\n                   DANH SACH NHAN VIEN NAM\n";
	cout << "Tong co " << Total_male << " nam" << endl;
	cout << " ______________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|\n";
	cout << "|---------+---------------------------+--------------+---------|\n";
	for(int i=0; i<size; i++){
		if(company_x[i].get_Sex() == "Nam"){
			cout << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
			cout << setw(26) << company_x[i].get_Full_name() << " |";
			Mydate tmp_birthday = company_x[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << company_x[i].get_Sex() << "   |" << endl;
		}
	}

	cout << "|_________|___________________________|______________|_________|\n";

	cout << "\n                   DANH SACH NHAN VIEN NU\n";
	cout << "Tong co " << size - Total_male << " nu" << endl;
	cout << " ______________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|\n";
	cout << "|---------+---------------------------+--------------+---------|\n";
	for(int i=0; i<size; i++){
		if(company_x[i].get_Sex() == "Nu"){
			cout << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
			cout << setw(26) << company_x[i].get_Full_name() << " |";
			Mydate tmp_birthday = company_x[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << company_x[i].get_Sex() << "   |" << endl;
		}
	}
	cout << "|_________|___________________________|______________|_________|\n";
}
// Thong ke theo nam sinh
void Birthday_statistical(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
	}

	// Sap xep theo nam sinh
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j].get_Birthday() > company_x[j+1].get_Birthday()){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}

	TextColor(7);
	cout << "\n           DANH SACH NHAN VIEN XEP THEO NGAY SINH\n";
	cout << " ______________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|\n";
	cout << "|---------+---------------------------+--------------+---------|\n";
	for(int i=0; i<size; i++){
		cout << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
		cout << setw(26) << company_x[i].get_Full_name() << " |";
		Mydate tmp_birthday = company_x[i].get_Birthday();
		cout << setw(4) << tmp_birthday << "  |";
		cout << setw(6) << company_x[i].get_Sex() << "   |" << endl;
	}
	cout << "|_________|___________________________|______________|_________|\n";
}
// Thong ke theo tien luong
void Salary_statistical(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
		company_x[i].set_Salary(off_work[i].get_Salary());
	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
		company_x[i].set_Salary(pro_work[i - off_num].get_Salary());
	}
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j].get_Salary() > company_x[j+1].get_Salary()){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}

	TextColor(7);
	cout << "\n                 DANH SACH NHAN VIEN THEO TIEN LUONG\n";
	cout << " _____________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh| Luong (dong) |\n";
	cout << "|---------+---------------------------+--------------+---------+--------------|\n";
	for(int i=0; i<size; i++){
		cout << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
		cout << setw(26) << company_x[i].get_Full_name() << " |";
		Mydate tmp_birthday = company_x[i].get_Birthday();
		cout << setw(4) << tmp_birthday << "  |";
		cout << setw(6) << company_x[i].get_Sex() << "   |";
		cout << setw(13) << company_x[i].get_Salary() << " |" << endl;
	}
	cout << "|_________|___________________________|______________|_________|______________|\n";
}
// Thong ke theo van phong
void Office_statistical(Office_worker *off_work, int off_num){

	TextColor(7);
	cout << "\n                 DANH SACH NHAN VIEN THEO VAN PHONG\n";
	cout << " ________________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|     Van phong   |\n";
	cout << "|---------+---------------------------+--------------+---------+-----------------|\n";
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Quan ly nhan su"){
			cout << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			cout << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << off_work[i].get_Sex() << "   |";
			cout << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Y tuong" || off_work[i].get_Office() == "Y Tuong"){
			cout << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			cout << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << off_work[i].get_Sex() << "   |";
			cout << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Thiet ke" || off_work[i].get_Office() == "Thiet Ke"){
			cout << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			cout << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << off_work[i].get_Sex() << "   |";
			cout << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Ke toan" || off_work[i].get_Office() == "Ke Toan"){
			cout << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			cout << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << off_work[i].get_Sex() << "   |";
			cout << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Marketing"){
			cout << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			cout << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << off_work[i].get_Sex() << "   |";
			cout << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Ky Thuat" || off_work[i].get_Office() == "Ky thuat"){
			cout << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			cout << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << off_work[i].get_Sex() << "   |";
			cout << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}

	cout << "|_________|___________________________|______________|_________|_________________|\n";
}
// Thong ke theo ngay vao cong ty
void Day_start_statistical(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
		company_x[i].set_Day_start(off_work[i].get_Day_start());
	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
		company_x[i].set_Day_start(pro_work[i - off_num].get_Day_start());
	}
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j].get_Day_start() > company_x[j+1].get_Day_start()){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}

	TextColor(7);
	cout << "\n                  DANH SACH NHAN VIEN THEO NGAY VAO CONG TY\n";
	cout << " _________________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh| Ngay vao cong ty |\n";
	cout << "|---------+---------------------------+--------------+---------+------------------|\n";
	for(int i=0; i<size; i++){
		cout << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
		cout << setw(26) << company_x[i].get_Full_name() << " |";
		Mydate tmp_birthday = company_x[i].get_Birthday();
		cout << setw(4) << tmp_birthday << "  |";
		cout << setw(6) << company_x[i].get_Sex() << "   |";
		Mydate tmp_day_start = company_x[i].get_Day_start();
		cout << setw(6) << tmp_day_start << "    |" << endl;
	}
	cout << "|_________|___________________________|______________|_________|__________________|\n";
}
// Thong ke theo ngay nghi
void Day_off_statistical(Production_worker *pro_work, int pro_num){

	TextColor(7);
	cout << "\n                    DANH SACH CONG NHAN THEO NGAY NGHI\n";
	cout << " __________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh| Ngay nghi |\n";
	cout << "|---------+---------------------------+--------------+---------+-----------|\n";
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Hai"){
			cout << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			cout << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << pro_work[i].get_Sex() << "   |";
			cout << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Ba"){
			cout << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			cout << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << pro_work[i].get_Sex() << "   |";
			cout << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Tu"){
			cout << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			cout << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << pro_work[i].get_Sex() << "   |";
			cout << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Nam"){
			cout << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			cout << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << pro_work[i].get_Sex() << "   |";
			cout << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Sau"){
			cout << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			cout << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << pro_work[i].get_Sex() << "   |";
			cout << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Bay"){
			cout << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			cout << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << pro_work[i].get_Sex() << "   |";
			cout << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Chu Nhat"){
			cout << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			cout << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << pro_work[i].get_Sex() << "   |";
			cout << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	cout << "|_________|___________________________|______________|_________|___________|\n";
}
// Thong ke theo ngay nghi cong nhan nu
void Day_off_female_statistical(Production_worker *pro_work, int pro_num){

	TextColor(7);
	cout << "\n                  DANH SACH NGAY NGHI CONG NHAN NU\n";
	cout << " __________________________________________________________________________ \n";
	cout << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh| Ngay nghi |\n";
	cout << "|---------+---------------------------+--------------+---------+-----------|\n";
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Sex() == "Nu"){
			cout << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			cout << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			cout << setw(4) << tmp_birthday << "  |";
			cout << setw(6) << pro_work[i].get_Sex() << "   |";
			cout << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	cout << "|_________|___________________________|______________|_________|___________|\n";
}


// Xuat danh sach nhan vien vao file
void List_office_file_output(Office_worker* &off_work, int off_num){
	// Sap xep danh sach
	for(int i=off_num-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(off_work[j] > off_work[j+1]){
				Office_worker tmp_office_worker = off_work[j];
				off_work[j] = off_work[j+1];
				off_work[j+1] = tmp_office_worker;
			}
		}
	}

	file_list << "\n                   	                         DANH SACH NHAN VIEN VAN PHONG\n";
	file_list << "Tong so " << off_num << " nhan vien." << endl;
	file_list << " _________________________________________________________________________________________________________________________________________________________ \n";
	file_list << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|                Que quan              | Ngay vao cong ty | Luong (dong) |     Van phong   |\n";
	file_list << "|---------+---------------------------+--------------+---------+--------------------------------------+------------------+--------------+-----------------|\n";
	for(int i=0; i<off_num; i++){
		file_list << off_work[i];
	}
	file_list << "|_________|___________________________|______________|_________|______________________________________|__________________|______________|_________________|\n";
}
// Xuat danh sach cong nhan vao file
void List_production_file_output(Production_worker* &pro_work, int pro_num){
	// Sap xep danh sach
	for(int i=pro_num-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(pro_work[j] > pro_work[j+1]){
				Production_worker tmp_production_worker = pro_work[j];
				pro_work[j] = pro_work[j+1];
				pro_work[j+1] = tmp_production_worker;
			}
		}
	}

	file_list << "\n                   	                         DANH SACH CONG NHAN SAN XUAT\n";
	file_list << "Tong so " << pro_num << " cong nhan." << endl;
	file_list << " ____________________________________________________________________________________________________________________________________________________________________________ \n";
	file_list << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|                Que quan              | Ngay vao cong ty | Luong (dong) | Dinh muc sp (sp/thang) | Ngay nghi |\n";
	file_list << "|---------+---------------------------+--------------+---------+--------------------------------------+------------------+--------------+------------------------+-----------|\n";
	for(int i=0; i<pro_num; i++){
		file_list << pro_work[i];
	}
	file_list << "|_________|___________________________|______________|_________|______________________________________|__________________|______________|________________________|___________|\n";
}
// Xuat danh sach nhan vien chuyen khoi cong ty vao file
void List_move_file_output(Move_worker* &mov_work, int mov_num){
	// Sap xep danh sach
	for(int i=mov_num-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(mov_work[j] > mov_work[j+1]){
				Move_worker tmp_move_worker = mov_work[j];
				mov_work[j] = mov_work[j+1];
				mov_work[j+1] = tmp_move_worker;
			}
		}
	}

	file_list << "\n                   	        DANH SACH NHAN VIEN CHUYEN DI\n";
	file_list << "Tong so " << mov_num << " nhan vien." << endl;
	file_list << " _________________________________________________________________________________ \n";
	file_list << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|  Ngay chuyen di  |\n";
	file_list << "|---------+---------------------------+--------------+---------+------------------|\n";
	for(int i=0; i<mov_num; i++){
		file_list << mov_work[i];
	}
	file_list << "|_________|___________________________|______________|_________|__________________|\n";
}


// Xuat bang thong ke nhan vien trong cong ty vao file
void Employee_statistical_file_output(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
		company_x[i].set_Native_place(off_work[i].get_Native_place());
		company_x[i].set_Day_start(off_work[i].get_Day_start());
		company_x[i].set_Salary(off_work[i].get_Salary());

	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
		company_x[i].set_Native_place(pro_work[i - off_num].get_Native_place());
		company_x[i].set_Day_start(pro_work[i - off_num].get_Day_start());
		company_x[i].set_Salary(pro_work[i - off_num].get_Salary());
	}

	// Sap xep danh sach theo ten Alphabet
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j] > company_x[j+1]){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}
	file_statistical << "\n                   	                         DANH SACH NHAN VIEN CONG TY\n";
	file_statistical << "Tong so: " << Company_X::Total_employee << " nhan vien" << endl;
	file_statistical << " _______________________________________________________________________________________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|                Que quan              | Ngay vao cong ty | Luong (dong) |\n";
	file_statistical << "|---------+---------------------------+--------------+---------+--------------------------------------+------------------+--------------|\n";
	for(int i=0; i<size; i++){
		file_statistical << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
		file_statistical << setw(26) << company_x[i].get_Full_name() << " |";
		Mydate tmp_birthday = company_x[i].get_Birthday();
		file_statistical << setw(4) << tmp_birthday << "  |";
		file_statistical << setw(6) << company_x[i].get_Sex() << "   |";
		file_statistical << setw(37) << company_x[i].get_Native_place() << " |";
		Mydate tmp_day_start = company_x[i].get_Day_start();
		file_statistical << setw(6) << tmp_day_start << "    |";
		file_statistical << setw(13) << company_x[i].get_Salary() << " |" << endl;
	}
	file_statistical << "|_________|___________________________|______________|_________|______________________________________|__________________|______________|\n";
}
// Xuat bang thong ke theo gioi tinh vao file
void Sex_statistical_file_output(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
	}

	// Sap xep theo nam sinh
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j].get_Birthday() > company_x[j+1].get_Birthday()){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}

	int Total_male = 0;
	for(int i=0; i<size; i++){
		if(company_x[i].get_Sex() == "Nam"){
			Total_male++;
		}
	}

	file_statistical << "\n                   DANH SACH NHAN VIEN NAM\n";
	file_statistical << "Tong so: " << Total_male << " nam" << endl;
	file_statistical << " ______________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|\n";
	file_statistical << "|---------+---------------------------+--------------+---------|\n";
	for(int i=0; i<size; i++){
		if(company_x[i].get_Sex() == "Nam"){
			file_statistical << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
			file_statistical << setw(26) << company_x[i].get_Full_name() << " |";
			Mydate tmp_birthday = company_x[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << company_x[i].get_Sex() << "   |" << endl;
		}
	}

	file_statistical << "|_________|___________________________|______________|_________|\n";

	file_statistical << "\n                   DANH SACH NHAN VIEN NU\n";
	file_statistical << "Tong so: " << size - Total_male << " nu" << endl;
	file_statistical << " ______________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|\n";
	file_statistical << "|---------+---------------------------+--------------+---------|\n";
	for(int i=0; i<size; i++){
		if(company_x[i].get_Sex() == "Nu"){
			file_statistical << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
			file_statistical << setw(26) << company_x[i].get_Full_name() << " |";
			Mydate tmp_birthday = company_x[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << company_x[i].get_Sex() << "   |" << endl;
		}
	}
	file_statistical << "|_________|___________________________|______________|_________|\n";
}
// Xuat bang thong ke theo nam sinh vao file
void Birthday_statistical_file_output(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
	}

	// Sap xep theo nam sinh
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j].get_Birthday() > company_x[j+1].get_Birthday()){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}

	file_statistical << "\n           DANH SACH NHAN VIEN XEP THEO NGAY SINH\n";
	file_statistical << " ______________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|\n";
	file_statistical << "|---------+---------------------------+--------------+---------|\n";
	for(int i=0; i<size; i++){
		file_statistical << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
		file_statistical << setw(26) << company_x[i].get_Full_name() << " |";
		Mydate tmp_birthday = company_x[i].get_Birthday();
		file_statistical << setw(4) << tmp_birthday << "  |";
		file_statistical << setw(6) << company_x[i].get_Sex() << "   |" << endl;
	}
	file_statistical << "|_________|___________________________|______________|_________|\n";
}
// Xuat bang thong ke theo tien luong vao file
void Salary_statistical_file_output(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
		company_x[i].set_Salary(off_work[i].get_Salary());
	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
		company_x[i].set_Salary(pro_work[i - off_num].get_Salary());
	}
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j].get_Salary() > company_x[j+1].get_Salary()){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}
	file_statistical << "\n                 DANH SACH NHAN VIEN THEO TIEN LUONG\n";
	file_statistical << " _____________________________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh| Luong (dong) |\n";
	file_statistical << "|---------+---------------------------+--------------+---------+--------------|\n";
	for(int i=0; i<size; i++){
		file_statistical << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
		file_statistical << setw(26) << company_x[i].get_Full_name() << " |";
		Mydate tmp_birthday = company_x[i].get_Birthday();
		file_statistical << setw(4) << tmp_birthday << "  |";
		file_statistical << setw(6) << company_x[i].get_Sex() << "   |";
		file_statistical << setw(13) << company_x[i].get_Salary() << " |" << endl;
	}
	file_statistical << "|_________|___________________________|______________|_________|______________|\n";
}
// Xuat bang thong ke theo van phong vao file
void Office_statistical_file_output(Office_worker *off_work, int off_num){

	file_statistical << "\n                 DANH SACH NHAN VIEN THEO VAN PHONG\n";
	file_statistical << " ________________________________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|     Van phong   |\n";
	file_statistical << "|---------+---------------------------+--------------+---------+-----------------|\n";
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Quan ly nhan su"){
			file_statistical << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << off_work[i].get_Sex() << "   |";
			file_statistical << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Y tuong" || off_work[i].get_Office() == "Y Tuong"){
			file_statistical << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << off_work[i].get_Sex() << "   |";
			file_statistical << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Thiet ke" || off_work[i].get_Office() == "Thiet Ke"){
			file_statistical << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << off_work[i].get_Sex() << "   |";
			file_statistical << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Ke toan" || off_work[i].get_Office() == "Ke Toan"){
			file_statistical << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << off_work[i].get_Sex() << "   |";
			file_statistical << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Marketing"){
			file_statistical << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << off_work[i].get_Sex() << "   |";
			file_statistical << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	for(int i=0; i<off_num; i++){
		if(off_work[i].get_Office() == "Ky Thuat" || off_work[i].get_Office() == "Ky thuat"){
			file_statistical << "|" << setw(8) << off_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << off_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = off_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << off_work[i].get_Sex() << "   |";
			file_statistical << setw(16) << off_work[i].get_Office() << " |" << endl;
		}
	}
	file_statistical << "|_________|___________________________|______________|_________|_________________|\n";
}
// Xuat bang thong ke theo ngay vao cong ty vao file
void Day_start_statistical_file_output(Office_worker *off_work, int off_num, Production_worker *pro_work, int pro_num){
	int size = off_num + pro_num;
	Company_X *company_x = new Company_X[size];
	for(int i=0; i<off_num; i++){
		company_x[i].set_Employee_code(off_work[i].get_Employee_code());
		company_x[i].set_Full_name(off_work[i].get_Full_name());
		company_x[i].set_Birthday(off_work[i].get_Birthday());
		company_x[i].set_Sex(off_work[i].get_Sex());
		company_x[i].set_Day_start(off_work[i].get_Day_start());
	}
	for(int i=off_num; i<size; i++){
		company_x[i].set_Employee_code(pro_work[i - off_num].get_Employee_code());
		company_x[i].set_Full_name(pro_work[i - off_num].get_Full_name());
		company_x[i].set_Birthday(pro_work[i - off_num].get_Birthday());
		company_x[i].set_Sex(pro_work[i - off_num].get_Sex());
		company_x[i].set_Day_start(pro_work[i - off_num].get_Day_start());
	}
	for(int i=size-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(company_x[j].get_Day_start() > company_x[j+1].get_Day_start()){
				Company_X tmp_company_x = company_x[j];
				company_x[j] = company_x[j+1];
				company_x[j+1] = tmp_company_x;
			}
		}
	}
	file_statistical << "\n                  DANH SACH NHAN VIEN THEO NGAY VAO CONG TY\n";
	file_statistical << " _________________________________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh| Ngay vao cong ty |\n";
	file_statistical << "|---------+---------------------------+--------------+---------+------------------|\n";
	for(int i=0; i<size; i++){
		file_statistical << "|" << setw(8) << company_x[i].get_Employee_code() << " |";
		file_statistical << setw(26) << company_x[i].get_Full_name() << " |";
		Mydate tmp_birthday = company_x[i].get_Birthday();
		file_statistical << setw(4) << tmp_birthday << "  |";
		file_statistical << setw(6) << company_x[i].get_Sex() << "   |";
		Mydate tmp_day_start = company_x[i].get_Day_start();
		file_statistical << setw(6) << tmp_day_start << "    |" << endl;
	}
	file_statistical << "|_________|___________________________|______________|_________|__________________|\n";
}
// Xuat bang thong ke theo ngay nghi vao file
void Day_off_statistical_file_output(Production_worker *pro_work, int pro_num){

	file_statistical << "\n                    DANH SACH CONG NHAN THEO NGAY NGHI\n";
	file_statistical << " __________________________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh| Ngay nghi |\n";
	file_statistical << "|---------+---------------------------+--------------+---------+-----------|\n";
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Hai"){
			file_statistical << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << pro_work[i].get_Sex() << "   |";
			file_statistical << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Ba"){
			file_statistical << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << pro_work[i].get_Sex() << "   |";
			file_statistical << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Tu"){
			file_statistical << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << pro_work[i].get_Sex() << "   |";
			file_statistical << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Nam"){
			file_statistical << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << pro_work[i].get_Sex() << "   |";
			file_statistical << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Sau"){
			file_statistical << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << pro_work[i].get_Sex() << "   |";
			file_statistical << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Thu Bay"){
			file_statistical << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << pro_work[i].get_Sex() << "   |";
			file_statistical << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Day_off() == "Chu Nhat"){
			file_statistical << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << pro_work[i].get_Sex() << "   |";
			file_statistical << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	file_statistical << "|_________|___________________________|______________|_________|___________|\n";
}
// Xuat bang thong ke theo ngay nghi cong nhan nu vao file
void Day_off_female_statistical_file_output(Production_worker *pro_work, int pro_num){
	file_statistical << "\n                  DANH SACH NGAY NGHI CONG NHAN NU\n";
	file_statistical << " __________________________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh| Ngay nghi |\n";
	file_statistical << "|---------+---------------------------+--------------+---------+-----------|\n";
	for(int i=0; i<pro_num; i++){
		if(pro_work[i].get_Sex() == "Nu"){
			file_statistical << "|" << setw(8) << pro_work[i].get_Employee_code() << " |";
			file_statistical << setw(26) << pro_work[i].get_Full_name() << " |";
			Mydate tmp_birthday = pro_work[i].get_Birthday();
			file_statistical << setw(4) << tmp_birthday << "  |";
			file_statistical << setw(6) << pro_work[i].get_Sex() << "   |";
			file_statistical << setw(10) << pro_work[i].get_Day_off() << " |" << endl;
		}
	}
	file_statistical << "|_________|___________________________|______________|_________|___________|\n";
}
// Xuat bang thong ke nhan vien chuyen di khoi cong ty
void List_move_statistical_file_output(Move_worker *mov_work, int size){
	file_statistical << "\n                   	        DANH SACH NHAN VIEN CHUYEN DI\n";
	file_statistical << " _________________________________________________________________________________ \n";
	file_statistical << "|  Ma nv  |        Ho va ten          |  Ngay sinh   |Gioi tinh|  Ngay chuyen di  |\n";
	file_statistical << "|---------+---------------------------+--------------+---------+------------------|\n";
	for(int i=0; i<size; i++){
		file_statistical << mov_work[i];
	}
	file_statistical << "|_________|___________________________|______________|_________|__________________|\n";
}


int main(){

	int mark_office_code;
	int off_num;

	file_office >> mark_office_code;
	file_office >> off_num;
	file_office.ignore();
	Office_worker *off_work = new Office_worker[off_num];
	for(int i=0; i<off_num; i++){
		file_office >> off_work[i];
	}
	
	int mark_production_code;
	int pro_num;

	file_production >> mark_production_code;
	file_production >> pro_num;
	file_production.ignore();
	Production_worker *pro_work = new Production_worker[pro_num];
	for(int i=0; i<pro_num; i++){
		file_production >> pro_work[i];
	}
	
	int mov_num;

	file_move >> mov_num;
	file_move.ignore();
	Move_worker *mov_work = new Move_worker[mov_num];
	for(int i=0; i<mov_num; i++){
		file_move >> mov_work[i];
	}

	MENU();

	while(true){

		TextColor(14);
		cout << "Nhap lua chon cua ban: ";
		string select;
		getline(cin, select);

		if(select == "0"){
			break;
		}
		else if(select == "1"){
			int check1, check2, check3;
			do {
				string worker_code;
				cout << "Nhap ma nhan vien tim: ";
				getline(cin, worker_code);
				Find(off_work, off_num, worker_code, check1);
				Find(pro_work, pro_num, worker_code, check2);
				Find(mov_work, mov_num, worker_code, check3);
				if(!check1 && !check2 && !check3){
					cout << "Ma ban nhap khong dung.\n";
					cout << "Chon 0 de thoat / so bat ky de tiep tuc: ";
					string select1;
					getline(cin, select1);
					if(select1 == "0") {
						break;
					}
					else {
						cout << "Vui long nhap lai!\n";
					}
				}
			} while(!check1 && !check2 && !check3);
		}
		else if(select == "2"){
			MENU_company();
			string select1;
			do {
				cout << "\tLua chon 1 / 2 / 3: ";
				getline(cin, select1);
				if(select1 == "1"){
					List_office(off_work, off_num);
				}
				else if(select1 == "2"){
					List_production(pro_work, pro_num);
				}
				else if(select1 == "3"){
					List_move(mov_work, mov_num);
				}
				else{
					cout << "Lua chon khong dung. Vui long nhap lai!\n";
				}
			} while (select1 != "1" && select1 != "2" && select1 != "3");
		}
		else if(select == "3"){
			cout << "\n\t1. Nhan vien van phong.\n";
			cout << "\t2. Cong nhan san xuat.\n";
			string select1;
			cout << "\nLua chon them nhan vien 1 / 2: ";
			getline(cin, select1);
			if(select1 == "1"){
				Add_employee_office(off_work, off_num, mark_office_code);
			}
			else if(select1 == "2"){
				Add_employee_production(pro_work, pro_num, mark_production_code);
			}
			else {
				cout << "Lua chon khong phu hop.\n";
			}
		}
		else if(select == "4"){
			cout << "\n\t1. Nhan vien van phong.\n";
			cout << "\t2. Cong nhan san xuat.\n";
			string select1;
			cout << "\nLua chon xoa nhan vien 1 / 2: ";
			getline(cin, select1);
			if(select1 == "1"){
				Move_worker move_worker;
				move_worker.set_Employee_code("");
				Delete_employee_office(off_work, off_num, move_worker);
				Add_employee_move(mov_work, mov_num, move_worker);
			}
			else if(select1 == "2"){
				Move_worker move_worker;
				move_worker.set_Employee_code("");
				Delete_employee_production(pro_work, pro_num, move_worker);
				Add_employee_move(mov_work, mov_num, move_worker);
			}
			else {
				cout << "Lua chon khong phu hop.\n";
			}
		}
		else if(select == "5"){
			cout << "\n\t1. Nhan vien van phong.\n";
			cout << "\t2. Cong nhan san xuat.\n";
			string select1;
			cout << "\nLua chon chinh sua nhan vien 1 / 2: ";
			getline(cin, select1);
			if(select1 == "1"){
				Edit_employee_office(off_work, off_num);
			}
			else if(select1 == "2"){
				Edit_employee_production(pro_work, pro_num);
			}
			else {
				cout << "Lua chon khong phu hop.\n";
			}
		}
		else if(select == "6"){
			MENU_statistical();
			cout << "\nLua chon 0 / 1 / 2  / 3 / 4 / 5 / 6 / 7 / 8: ";
			string select1;
			getline(cin, select1);
			if(select1 == "0"){
				Employee_statistical(off_work, off_num, pro_work, pro_num);
			}
			else if(select1 == "1"){
				Sex_statistical(off_work, off_num, pro_work, pro_num);
			}
			else if(select1 == "2"){
				Birthday_statistical(off_work, off_num, pro_work, pro_num);
			}
			else if(select1 == "3"){
				Salary_statistical(off_work, off_num, pro_work, pro_num);
			}
			else if(select1 == "4"){
				Office_statistical(off_work, off_num);
			}
			else if(select1 == "5"){
				Day_start_statistical(off_work, off_num, pro_work, pro_num);
			}
			else if(select1 == "6"){
				Day_off_statistical(pro_work, pro_num);
			}
			else if(select1 == "7"){
				Day_off_female_statistical(pro_work, pro_num);
			}
			else if(select1 == "8"){
				List_move(mov_work, mov_num);
			}
			else{
				cout << "Lua chon khong phu hop.\n";
			}
		}
		else {
			cout << "Lua chon khong dung. Vui long nhap lai!\n";
		}
		system("pause");
		system("cls");
		MENU();
	}

	// Xuat danh sach vao file
	List_office_file_output(off_work, off_num);
	file_list << endl;
	List_production_file_output(pro_work, pro_num);
	file_list << endl;
	List_move_file_output(mov_work, mov_num);

	// Xuat du lieu thong ke vao file
	Employee_statistical_file_output(off_work, off_num, pro_work, pro_num);
	file_statistical << endl;
	Sex_statistical_file_output(off_work, off_num, pro_work, pro_num);
	file_statistical << endl;
	Birthday_statistical_file_output(off_work, off_num, pro_work, pro_num);
	file_statistical << endl;
	Salary_statistical_file_output(off_work, off_num, pro_work, pro_num);
	file_statistical << endl;
	Office_statistical_file_output(off_work, off_num);
	file_statistical << endl;
	Day_start_statistical_file_output(off_work, off_num, pro_work, pro_num);
	file_statistical << endl;
	Day_off_statistical_file_output(pro_work, pro_num);
	file_statistical << endl;
	Day_off_female_statistical_file_output(pro_work, pro_num);
	file_statistical << endl;
	List_move_statistical_file_output(mov_work, mov_num);
	file_statistical << endl;

	Change_file(mov_work, mov_num);
	Change_file(off_work, off_num, mark_office_code);
	Change_file(pro_work, pro_num, mark_production_code);

	file_office.close();
	file_production.close();
	file_move.close();
	file_list.close();
	file_statistical.close();

	return 0;
}