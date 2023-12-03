#include<iostream>
using namespace std;
#define max 1000

// 定义一个结构体 person 用于存储个人信息
struct person {
string m_name; // 姓名
int m_sex; // 性别，1代表男性，2代表女性
int m_age; // 年龄
string m_phone; // 联系电话
string m_addr; // 住址
};

// 定义一个结构体 addressbook 用于存储通讯录
struct addressbook {
struct person personarray[max]; // 存储个人信息的数组
int m_size; // 当前通讯录大小
};

// 函数：添加联系人到通讯录
void addperson(addressbook* abs) {
if (abs->m_size > max) {
cout << "通讯录已满，请先删除一些人员" << endl;
return;
} else {
// 依次输入个人信息
string name;
cout << "请输入姓名：" << endl;
cin >> name;
abs->personarray[abs->m_size].m_name = name;
cout << "请输入性别：" << endl;
cout << "1———男" << endl;
cout << "2———女" << endl;
int sex = 0;
while (true) {
cin >> sex;
if (sex == 1 || sex == 2) {
abs->personarray[abs->m_size].m_sex = sex;
break;
} else {
cout << "输入有误，请重新输入" << endl;
}
}
cout << "请输入年龄：" << endl;
int age = 0;
cin >> age;
abs->personarray[abs->m_size].m_age = age;
cout << "请输入联系电话：" << endl;
string phone;
cin >> phone;
abs->personarray[abs->m_size].m_phone = phone;
cout << "请输入地址：" << endl;
string address;
cin >> address;
abs->personarray[abs->m_size].m_addr = address;
abs->m_size++;
cout << "添加成功！" << endl;
system("pause");
system("cls");
}
}

// 函数：显示通讯录中的所有联系人
void showperson(addressbook* abs) {
if (abs->m_size == 0) {
cout << "当前记录为空！" << endl;
} else {
for (int i = 0; i < abs->m_size; i++) {
cout << "姓名: " << abs->personarray[i].m_name << "\t";
cout << "性别: " << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
cout << "年龄: " << abs->personarray[i].m_age << "\t";
cout << "电话: " << abs->personarray[i].m_phone << "\t";
cout << "住址: " << abs->personarray[i].m_addr << endl;
}
}
system("pause");
system("cls");
}

// 函数：查找指定姓名的联系人
int isexist(addressbook* abs, string name) {
for (int i = 0; i < abs->m_size; i++) {
if (abs->personarray[i].m_name == name) {
return i;
}
}
return -1;
}

// 函数：根据姓名查找联系人并显示信息
void findperson(addressbook* abs) {
cout << "请输入你要查找的联系人：" << endl;
string name;
cin >> name;
int ret = isexist(abs, name);
if (ret != -1) {
cout << "姓名: " << abs->personarray[ret].m_name << "\t";
cout << "性别: " << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
cout << "年龄: " << abs->personarray[ret].m_age << "\t";
cout << "电话: " << abs->personarray[ret].m_phone << "\t";
cout << "住址: " << abs->personarray[ret].m_addr << endl;
} else {
cout << "查无此人" << endl;
}
system("pause");
system("cls");
}

// 函数：删除指定姓名的联系人
void delectperson(addressbook* abs) {
cout << "请输入你要删除的联系人：" << endl;
string name;
cin >> name;
int ret = isexist(abs, name);
if (ret != -1) {
for (int i = ret; i < abs->m_size; i++) {
abs->personarray[i] = abs->personarray[i + 1];
}
abs->m_size--;
cout << "删除成功" << endl;
} else {
cout << "查无此人" << endl;
}
}

// 函数：修改指定姓名的联系人信息
void modifyperson(addressbook* abs) {
cout << "请输入你要修改的联系人：" << endl;
string name;
cin >> name;
int ret = isexist(abs, name);
if (ret != -1) {
string new_name;
cout << "请输入新的姓名: " << endl;
// 接下来按照上述的方法依次输入其他信息并更新记录
} else {
cout << "查无此人" << endl;
}
}

// 主函数
int main() {
addressbook wm; // 创建通讯录实例
int choice = 0;
while (true) {
cout << "" << endl;
cout << "通讯录管理系统" << endl;
cout << "0.退出系统：" << endl;
cout << "1.添加联系人：" << endl;
cout << "2.显示联系人：" << endl;
cout << "3.删除联系人：" << endl;
cout << "4.查找联系人：" << endl;
cout << "5.修改联系人：" << endl;
cout << "" << endl;
cout << "请选择操作：" << endl;
cin >> choice;
// 根据用户选择执行不同的操作
switch (choice) {
case 0:
cout << "感谢使用通讯录管理系统，再见！" << endl;
return 0;
case 1:
addperson(&wm);
break;
case 2:
showperson(&wm);
break;
case 3:
delectperson(&wm);
break;
case 4:
findperson(&wm);
break;
case 5:
modifyperson(&wm);
break;
default:
cout << "无效的选择，请重新输入：" << endl;
break;
}
}
return 0;
}
