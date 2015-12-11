#ifndef _L6470_H_
#define _L6470_H_

#include <arduino.h>
#include <SPI.h>
#include <MsTimer2.h>
#include <stdio.h>

class L6470 
{
public:
	L6470(int mosi, int miso, int sck, int ss, int busy); //コンストラクタ

public:
	//各値をセットするメソッド
	void setparam_abspos(long val);
	void setparam_elpos(long val);
	void setparam_mark(long val);
	void setparam_acc(long val);
	void setparam_dec(long val);
	void setparam_maxspeed(long val);
	void setparam_minspeed(long val);
	void setparam_fsspd(long val);
	void setparam_kvalhold(long val);
	void setparam_kvalrun(long val);
	void setparam_kvalacc(long val);
	void setparam_kvaldec(long val);
	void setparam_intspd(long val);
	void setparam_stslp(long val);
	void setparam_fnslpacc(long val);
	void setparam_fnslpdec(long val);
	void setparam_ktherm(long val);
	void setparam_ocdth(long val);
	void setparam_stallth(long val);
	void setparam_stepmood(long val);
	void setparam_alareen(long val);
	void setparam_config(long val);

	//各値を取得するメソッド
	long getparam(int add,int bytes);
	long getparam_abspos();
	long getparam_elpos();
	long getparam_mark();
	long getparam_speed();
	long getparam_acc();
	long getparam_dec();
	long getparam_maxspeed();
	long getparam_minspeed();
	long getparam_fsspd();
	long getparam_kvalhold();
	long getparam_kvalrun();
	long getparam_kvalacc();
	long getparam_kvaldec();
	long getparam_intspd();
	long getparam_stslp();
	long getparam_fnslpacc();
	long getparam_fnslpdec();
	long getparam_ktherm();
	long getparam_adcout();
	long getparam_ocdth();
	long getparam_stallth();
	long getparam_stepmood();
	long getparam_alareen();
	long getparam_config();
	long getparam_status();

public:
	//主な動作のメソッド
	void L6470_setup();
	void run(int dia,long spd);
	void stepclock(int dia);
	void move(int dia,long n_step);
	void goTo(long pos);
	void gotodia(int dia,int pos);
	void gountil(int act,int dia,long spd);
    void gomark();
	void relesesw(int act,int dia);
	void gohome();
	void resetpos();
	void resetdevice();
	void softstop();
	void hardstop();
	void softhiz();
	void hardhiz();
	long getstatus();
	void transfer(int add,int bytes,long val);
	void send(unsigned char add_or_val);
	void busydelay(long time);
	int busy_flag();

private:
	int spi_mosi_pin, spi_miso_pin, spi_sck_pin, spi_ss_pin, busy_pin;
};

#endif 