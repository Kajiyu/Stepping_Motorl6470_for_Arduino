#ifndef _L6470_H_
#define _L6470_H_

#include <arduino.h>
#include <SPI.h>

class L6470 
{
public:
	L6470(int mosi, int miso, int sck, int ss, int busy); //コンストラクタ

public:
	//各値をセットするメソッド
	void setparam_abspos(int machine, long val);
	void setparam_elpos(int machine, long val);
	void setparam_mark(int machine, long val);
	void setparam_acc(int machine, long val);
	void setparam_dec(int machine, long val);
	void setparam_maxspeed(int machine, long val);
	void setparam_minspeed(int machine, long val);
	void setparam_fsspd(int machine, long val);
	void setparam_kvalhold(int machine, long val);
	void setparam_kvalrun(int machine, long val);
	void setparam_kvalacc(int machine, long val);
	void setparam_kvaldec(int machine, long val);
	void setparam_intspd(int machine, long val);
	void setparam_stslp(int machine, long val);
	void setparam_fnslpacc(int machine, long val);
	void setparam_fnslpdec(int machine, long val);
	void setparam_ktherm(int machine, long val);
	void setparam_ocdth(int machine, long val);
	void setparam_stallth(int machine, long val);
	void setparam_stepmood(int machine, long val);
	void setparam_alareen(int machine, long val);
	void setparam_config(int machine, long val);

	//各値を取得するメソッド
	long getparam(int machine, int add, int bytes);
	long getparam_abspos(int machine);
	long getparam_elpos(int machine);
	long getparam_mark(int machine);
	long getparam_speed(int machine);
	long getparam_acc(int machine);
	long getparam_dec(int machine);
	long getparam_maxspeed(int machine);
	long getparam_minspeed(int machine);
	long getparam_fsspd(int machine);
	long getparam_kvalhold(int machine);
	long getparam_kvalrun(int machine);
	long getparam_kvalacc(int machine);
	long getparam_kvaldec(int machine);
	long getparam_intspd(int machine);
	long getparam_stslp(int machine);
	long getparam_fnslpacc(int machine);
	long getparam_fnslpdec(int machine);
	long getparam_ktherm(int machine);
	long getparam_adcout(int machine);
	long getparam_ocdth(int machine);
	long getparam_stallth(int machine);
	long getparam_stepmood(int machine);
	long getparam_alareen(int machine);
	long getparam_config(int machine);
	long getparam_status(int machine);

public:
	//主な動作のメソッド
	void L6470_setup(int machine);
	void run(int machine, int dia,long spd);
	void stepclock(int machine, int dia);
	void move(int machine, int dia,long n_step);
	void goTo(int machine, long pos);
	void gotodia(int machine, int dia,int pos);
	void gountil(int machine, int act,int dia,long spd);
    void gomark(int machine);
	void relesesw(int machine, int act,int dia);
	void gohome(int machine);
	void resetpos(int machine);
	void resetdevice(int machine);
	void softstop(int machine);
	void hardstop(int machine);
	void softhiz(int machine);
	void hardhiz(int machine);
	long getstatus(int machine);
	void busydelay(long time);

	void transfer(int machine, int add,int bytes,long val);
	void send(int machine, unsigned char add_or_val);
	int busy_flag(int machine);

private:
	int spi_mosi_pin, spi_miso_pin, spi_sck_pin, spi_ss_pin, busy_pin;
};

#endif 