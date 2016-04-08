#include <iostream>
#include <string>
#include "Package.h"
using std::string;
using std::cout;
using std::endl;


Package::Package(const string &sName, const string &sAddress, 
	const string &sCity, const string &sState, const string &sZIP,
	double wght, double costPOunce,
	const string &rName, const string &rAddress, 
	const string &rCity, const string &rState, const string &rZIP) {

	senderName = sName;
	senderAddress = sAddress;
	senderCity = sCity;
	senderState = sState;
	senderZIP = sZIP;

	setWeight(wght);
	setCostPerOunce(costPOunce);

	recipientName = rName;
	recipientAddress = rAddress;
	recipientCity = rCity;
	recipientState = rState;
	recipientZIP = rZIP;

}

void Package::setSenderName(const string &sName) {
	senderName = sName;
}
string Package::getSenderName() const {
	return senderName;
}

void Package::setSenderAddress(const string &sAddress) {
	senderAddress = sAddress;
}

string Package::getSenderAddress() const {
	return senderAddress;
}

void Package::setSenderCity(const string &sCity) {
	senderCity = sCity;
}

string Package::getSenderCity() const {
	return senderCity;
}

void Package::setSenderState(const string &sState) {
	senderState = sState;
}

string Package::getSenderState() const {
	return senderState;
}

void Package::setSenderZIP(const string &sZIP) {
	senderZIP = sZIP;
}

string Package::getSenderZIP() const {
	return senderZIP;
}


// set and get functions for recipient
void Package::setRecipientName(const string &sName) {
	recipientName = sName;
}
string Package::getRecipientName() const {
	return recipientName;
}

void Package::setRecipientAddress(const string &sAddress) {
	recipientAddress = sAddress;
}

string Package::getRecipientAddress() const {
	return recipientAddress;
}

void Package::setRecipientCity(const string &sCity) {
	recipientCity = sCity;
}

string Package::getRecipientCity() const {
	return recipientCity;
}

void Package::setRecipientState(const string &sState) {
	recipientState = sState;
}

string Package::getRecipientState() const {
	return recipientState;
}

void Package::setRecipientZIP(const string &sZIP) {
	recipientZIP = sZIP;
}

string Package::getRecipientZIP() const {
	return recipientZIP;
}

// package weight and cost
void Package::setWeight(double wght) {
	weight = ((wght > 0) ? wght : 0);
}

double Package::getWeight() const {
	return weight;
}

void Package::setCostPerOunce(double costPOunce) {
	costPerOunce = ((costPOunce > 0) ? costPOunce : 0);
}

double Package::getCostPerOunce() const {
	return costPerOunce;
}

double Package::calculateCost() const {
	return getWeight()*getCostPerOunce();
}

// printf info
void Package::printfPackageInfo() const {
	cout << "Package info:" << endl
		<< "Sender name: " << getSenderName() << endl
		<< "Sender address: " << getSenderAddress() << endl
		<< "Sender city: " << getSenderCity() << endl
		<< "Sender state: " << getSenderState() << endl
		<< "Sender ZIP: " << getSenderZIP() << endl
		<< "Recipient name: " << getRecipientName() << endl
		<< "Recipient address: " << getRecipientAddress() << endl
		<< "Recipient city: " << getRecipientCity() << endl
		<< "Recipient state: " << getRecipientState() << endl
		<< "Recipient ZIP: " << getRecipientZIP() << endl
		<< "Package weight: " << getWeight() << ((getWeight() == 1) ? " ounce" : " ounces") << endl
		<< "Cost per ounce: " << getCostPerOunce() << endl
		<< "Package cost w/out flat fee, w/out fee p/ounce: " << calculateCost() << endl;
}