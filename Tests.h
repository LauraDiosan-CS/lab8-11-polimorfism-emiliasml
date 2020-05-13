#pragma once

class Tests {
private:
	void testSeries();
	void testPhone();
	void testDrone();
	void testUser();
	void testIRepository();
	void testRepositoryFile();
	void testRepositoryFileCSV();
	void testRepositoryFileHTML();
	void testService();

public:
	Tests() {}
	void runTests();
	~Tests() {}
};