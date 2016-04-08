#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using std::string;

class Package {
public:
	Package(const string &, const string &, const string &, const string &, const string &,
		double, double,
		const string &, const string &, const string &, const string &, const string &);

	// set and get functions for sender
	void setSenderName(const string &);
	string getSenderName() const;

	void setSenderAddress(const string &);
	string getSenderAddress() const;

	void setSenderCity(const string &);
	string getSenderCity() const;

	void setSenderState(const string &);
	string getSenderState() const;

	void setSenderZIP(const string &);
	string getSenderZIP() const;


	// set and get functions for recipient
	void setRecipientName(const string &);
	string getRecipientName() const;

	void setRecipientAddress(const string &);
	string getRecipientAddress() const;

	void setRecipientCity(const string &);
	string getRecipientCity() const;

	void setRecipientState(const string &);
	string getRecipientState() const;

	void setRecipientZIP(const string &);
	string getRecipientZIP() const;

	void setWeight(double);
	double getWeight() const;

	void setCostPerOunce(double);
	double getCostPerOunce() const;

	double calculateCost() const;

	void printfPackageInfo() const;
	
private:
	// sender info
	string senderName;
	string senderAddress;
	string senderCity;
	string senderState;
	string senderZIP;

	// package info
	double weight;
	double costPerOunce;

	// recipient info
	string recipientName;
	string recipientAddress;
	string recipientCity;
	string recipientState;
	string recipientZIP;
};

#endif // !PACKAGE_H
