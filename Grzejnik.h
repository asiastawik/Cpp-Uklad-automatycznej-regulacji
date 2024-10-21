#pragma once

class Grzejnik
{
public:
	Grzejnik();
	~Grzejnik();
	const float moc = 5000; //w watach; "moc nominalna(wartosc zmiennoprzecinkowa, stala, ustalana przy konstrukcji obiektu)"
	float procent;
	void ustawGrzejnik(float poziom);
	float getAktualnaMoc() { return procent / 100.0 * moc; } //"aktualny poziom mocy (wartosc zmiennoprzecinkowa oznaczajaca procent mocy emitowanej w danej chwili)"
};