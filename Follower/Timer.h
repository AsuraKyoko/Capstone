

class Timer
{
private:
	int count;
	int trig;

public:
	Timer(int trig);
	bool update();
	int getCount();
};