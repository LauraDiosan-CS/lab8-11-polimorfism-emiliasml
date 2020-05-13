#include "Tests.h"
#include <assert.h>
#include "Series.h"
#include "Phone.h"
#include "Drone.h"
#include "User.h"
#include "IRepository.h"
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileHTML.h"
#include "SerializerSeries.h"
#include "Service.h"

void Tests::testSeries() {
	Series s;
	Series ss("producer", "model", 1);
	Series sss = ss;
	assert(s.getNr() == 0);
	assert(ss.getProducer() == "producer");
	assert(ss.getModel() == "model");
	assert(ss.getNr() == 1);
	assert(sss.getProducer() == "producer");
	assert(sss.getModel() == "model");
	assert(ss.getNr() == 1);

	ss.setProducer("p");
	ss.setModel("m");
	ss.setNr(11);
	assert(ss.getProducer() == "p");
	assert(ss.getModel() == "m");
	assert(ss.getNr() == 11);
}

void Tests::testPhone(){
	vector<string> op = { "op1", "op2" }, ope = { "op1", "op2", "op3" };
	Phone ph("p", "m", 1, op);
	assert(ph.getProducer() == "p");
	assert(ph.getModel() == "m");
	assert(ph.getNr() == 1);
	assert(ph.getOperators() == op);
	Phone pho = ph;
	assert(pho.getProducer() == "p");
	assert(pho.getModel() == "m");
	assert(pho.getNr() == 1);
	assert(pho.getOperators() == op);

	ph.setProducer("pro");
	ph.setModel("mo");
	ph.setNr(2);
	ph.setOperators(ope);
	assert(ph.getProducer() == "pro");
	assert(ph.getModel() == "mo");
	assert(ph.getNr() == 2);
	assert(ph.getOperators() == ope);
}

void Tests::testDrone(){
	Drone d("m", "p", 3, 4);
	assert(d.getProducer() == "m");
	assert(d.getModel() == "p");
	assert(d.getNr() == 3);
	assert(d.getNrRotors() == 4);
	Drone dr = d;
	assert(dr.getProducer() == "m");
	assert(dr.getModel() == "p");
	assert(dr.getNr() == 3);
	assert(dr.getNrRotors() == 4);

	d.setProducer("pr");
	d.setModel("mo");
	d.setNr(11);
	d.setNrRotors(22);
	assert(d.getProducer() == "pr");
	assert(d.getModel() == "mo");
	assert(d.getNr() == 11);
	assert(d.getNrRotors() == 22);
}

void Tests::testUser(){
	User u("u", "p");
	assert(u.getUserName() == "u");
	assert(u.getPassword() == "p");
	User uu = u;
	assert(uu.getUserName() == "u");
	assert(uu.getPassword() == "p");
	
	u.setUserName("uu");
	u.setPassword("pp");
	assert(u.getUserName() == "uu");
	assert(u.getPassword() == "pp");
}

void Tests::testIRepository(){
	vector<string> op1 = { "op1", "op2" }, op2 = { "op1", "op2", "op3" };
	Series s("p", "m", 1);
	IRepository<Series> repo;
	assert(repo.size() == 0);
	repo.add(s);
	assert(repo.size() == 1);
	repo.remove(s);
	assert(repo.size() == 0);

	Series* s1 = new Series("p1", "m1", 1);
	Series* s2 = new Phone("p2", "m2", 2, op2);
	Series* s3 = new Drone("p3", "m3", 3, 4);
	IRepository<Series*> rs;
	assert(rs.size() == 0);
	rs.add(s1);
	rs.add(s2);
	rs.add(s3);
	assert(rs.size() == 3);
	vector<Series*> v = rs.getAll();
	assert(v[0] == s1);
	assert(v[1] == s2);
	assert(v[2] == s3);

	assert(rs.find(s1) != -1);
	rs.remove(s1);
	assert(rs.find(s1) == -1);
	assert(rs.size() == 2);

	rs.clear();
	assert(rs.size() == 0);
	delete[]s3, s2, s1;

}

void Tests::testRepositoryFile(){
	SerializerSeries* s = new SerializerSeries();
	RepositoryFile<Series*> repo("Tests.txt", s);
	vector<string> op1 = { "op1", "op2" }, op2 = { "op1", "op2" , "op3"};
	assert(repo.size() == 0);
	Series* p = new Phone("ph", "mo", 1, op1);
	Series* p2 = new Phone("ph", "mo", 1, op2);
	repo.add(p);
	repo.add(p2);
	assert(repo.size() == 2);
	assert(repo.find(p) != -1);
	repo.remove(p);
	assert(repo.find(p) == -1);
	assert(repo.size() == 1);
	repo.clear();
	assert(repo.size() == 0);
	delete[] p2, p;
}

void Tests::testRepositoryFileCSV(){
	SerializerSeries* s = new SerializerSeries();
	RepositoryFileCSV<Series*> repo("Tests.csv", s);
	repo.loadFromFile();
	vector<string> op1 = { "op1", "op2" }, op2 = { "op1", "op2" , "op3" };
	Series* p = new Phone("m", "p", 1, op1);
	repo.add(p);
	Series* pp = new Phone("m", "p", 12, op2);
	repo.add(pp);
	assert(repo.find(pp) != -1);
	repo.remove(pp);
	assert(repo.find(pp) == -1);
	repo.clear();
	assert(repo.size() == 0);
	delete[] pp, p;
}

void Tests::testRepositoryFileHTML(){
	SerializerSeries* s = new SerializerSeries();
	RepositoryFileCSV<Series*> repo("Tests.html", s);
	repo.loadFromFile();
	vector<string> op1 = { "op1", "op2" }, op2 = { "op1", "op2" , "op3" };
	Series* p = new Phone("m", "p", 1, op1);
	repo.add(p);
	Series* pp = new Phone("m", "p", 12, op2);
	repo.add(pp);
	assert(repo.find(pp) != -1);
	repo.remove(pp);
	assert(repo.find(pp) == -1);
	repo.clear();
	assert(repo.size() == 0);
	delete[] pp, p;
}

void Tests::testService(){
}

void Tests::runTests()
{
	testSeries();
	testPhone();
	testDrone();
	testUser();
	testIRepository();
	testRepositoryFile();
	testRepositoryFileCSV();
	testRepositoryFileHTML();
	testService();
}
