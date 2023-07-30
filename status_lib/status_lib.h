#pragma once

class State {
public:
	virtual void print_timer(int& timer_seconds) = 0;
};

class State_1 : public State {
public:
	State_1(int timer_seconds) : timer_seconds{ timer_seconds }{}
	void increment_timer(char** argv);
	int timer_seconds = 0;
	int status = 0;

private:
	void print_timer(int& timer_seconds) override {
		std::cout << timer_seconds << std::endl;
	};
};

class State_2 : public State, public State_1 {
public:
	State_2(int timer_seconds) : State_1{ timer_seconds } {
		State_1 state1{ 0 };
		state1.timer_seconds = timer_seconds;

		this->status = state1.status;
	};
	void decrement_timer(char** argv);
	int status = 0;

private:
	void print_timer(int& timer_seconds) override {
		std::cout << timer_seconds << std::endl;
	};
};

class State_3 : public State, public State_1 {
public:
	State_3(int timer_seconds) : State_1{ timer_seconds } {
		State_1 state1{ 0 };
		state1.timer_seconds = timer_seconds;

		this->status = state1.status;
	};
	void blinking_timer(char** argv);
	int status = 0;

private:
	void print_timer(int& timer_seconds) override {
		std::cout << timer_seconds;
	};
};