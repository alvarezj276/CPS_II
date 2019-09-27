// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title : contact_list.h
// Course : Computational Problem Solving II (CPET-321)
// Developer : Matthew Chu
// Date : Fall 2019 (2191)
// Description : Project #3 Contact List
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef CONTACT_LIST_H_
#define CONTACT_LIST_H_
#include <string>

struct contact
{
  std::string name;
  std::string cellnumber;
  std::string email;
  bool ICE;
  contact *nextaddr;
};

extern bool active;

void Show(contact *head);

contact *Update(contact *head, int m);

contact *Read();

contact *Delete(contact *head, int m);

contact *Insert(contact *head, int m);

void Toggle(contact *head, int m);

void Write(contact *head);

void quit();

void menu();

#endif /* CONTACT_LIST_H_ */
