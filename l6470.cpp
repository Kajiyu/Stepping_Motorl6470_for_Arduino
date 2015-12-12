#include "l6470.h"


//一台目

//コンストラクタ：初期化
L6470::L6470(int mosi, int miso, int sck, int ss, int busy)
: spi_mosi_pin(mosi), spi_miso_pin(miso), spi_sck_pin(sck), spi_ss_pin(ss), busy_pin(busy) {}


//各値をセットするメソッド
void L6470::setparam_abspos(int machine, long val){
	transfer(machine, 0x01,3,val);
}

void L6470::setparam_elpos(int machine, long val){
	transfer(machine, 0x02,2,val);
}

void L6470::setparam_mark(int machine, long val){
	transfer(machine, 0x03,3,val);
}

void L6470::setparam_acc(int machine, long val){
	transfer(machine, 0x05,2,val);
}

void L6470::setparam_dec(int machine, long val){
	transfer(machine, 0x06,2,val);
}

void L6470::setparam_maxspeed(int machine, long val){
	transfer(machine, 0x07,2,val);
}

void L6470::setparam_minspeed(int machine, long val){
	transfer(machine, 0x08,2,val);
}

void L6470::setparam_fsspd(int machine, long val){
	transfer(machine, 0x15,2,val);
}

void L6470::setparam_kvalhold(int machine, long val){
	transfer(machine, 0x09,1,val);
}

void L6470::setparam_kvalrun(int machine, long val){
	transfer(machine, 0x0a,1,val);
}

void L6470::setparam_kvalacc(int machine, long val){
	transfer(machine, 0x0b,1,val);
}

void L6470::setparam_kvaldec(int machine, long val){
	transfer(machine, 0x0c,1,val);
}

void L6470::setparam_intspd(int machine, long val){
	transfer(machine, 0x0d,2,val);
}

void L6470::setparam_stslp(int machine, long val){
	transfer(machine, 0x0e,1,val);
}

void L6470::setparam_fnslpacc(int machine, long val){
	transfer(machine, 0x0f,1,val);
}

void L6470::setparam_fnslpdec(int machine, long val){
	transfer(machine, 0x10,1,val);
}

void L6470::setparam_ktherm(int machine, long val){
	transfer(machine, 0x11,1,val);
}

void L6470::setparam_ocdth(int machine, long val){
	transfer(machine, 0x13,1,val);
}

void L6470::setparam_stallth(int machine, long val){
	transfer(machine, 0x14,1,val);
}

void L6470::setparam_stepmood(int machine, long val){
	transfer(machine, 0x16,1,val);
}

void L6470::setparam_alareen(int machine, long val){
	transfer(machine, 0x17,1,val);
}

void L6470::setparam_config(int machine, long val){
	transfer(machine, 0x18,2,val);
}

//各値を取得するメソッド
long L6470::getparam(int machine, int add, int bytes){//1台目に送信
  long val=0;
  int send_add = add | 0x20;
  send(machine, send_add);
  for(int i = 0; i <= bytes-1 ;i++){
    val = val << 8;
    digitalWrite(spi_ss_pin, LOW); // ~SSイネーブル。
    if(machine != 2) { //一台目なら
      SPI.transfer(0x00);// 0送信。
      val = val | SPI.transfer(0x00); // アドレスもしくはデータ送信。
    } else { //二台目なら
      val = val | SPI.transfer(0x00); // アドレスもしくはデータ送信。
      SPI.transfer(0x00);// 0送信。
    }
    digitalWrite(spi_ss_pin, HIGH); // ~SSディスエーブル 
  }
  return val;
}

long L6470::getparam_abspos(int machine){
	return getparam(machine, 0x01,3);
}

long L6470::getparam_elpos(int machine){
	return getparam(machine, 0x02,2);
}

long L6470::getparam_mark(int machine){
	return getparam(machine, 0x03,3);
}

long L6470::getparam_speed(int machine){
	return getparam(machine, 0x04,3);
}

long L6470::getparam_acc(int machine){
	return getparam(machine, 0x05,2);
}

long L6470::getparam_dec(int machine){
	return getparam(machine, 0x06,2);
}

long L6470::getparam_maxspeed(int machine){
	return getparam(machine, 0x07,2);
}

long L6470::getparam_minspeed(int machine){
	return getparam(machine, 0x08,2);
}

long L6470::getparam_fsspd(int machine){
	return getparam(machine, 0x15,2);
}

long L6470::getparam_kvalhold(int machine){
	return getparam(machine, 0x09,1);
}

long L6470::getparam_kvalrun(int machine){
	return getparam(machine, 0x0a,1);
}

long L6470::getparam_kvalacc(int machine){
	return getparam(machine, 0x0b,1);
}

long L6470::getparam_kvaldec(int machine){
	return getparam(machine, 0x0c,1);
}

long L6470::getparam_intspd(int machine){
	return getparam(machine, 0x0d,2);
}

long L6470::getparam_stslp(int machine){
	return getparam(machine, 0x0e,1);
}

long L6470::getparam_fnslpacc(int machine){
	return getparam(machine, 0x0f,1);
}

long L6470::getparam_fnslpdec(int machine){
	return getparam(machine, 0x10,1);
}

long L6470::getparam_ktherm(int machine){
	return getparam(machine, 0x11,1);
}

long L6470::getparam_adcout(int machine){
	return getparam(machine, 0x12,1);
}

long L6470::getparam_ocdth(int machine){
	return getparam(machine, 0x13,1);
}

long L6470::getparam_stallth(int machine){
	return getparam(machine, 0x14,1);
}

long L6470::getparam_stepmood(int machine){
	return getparam(machine, 0x16,1);
}

long L6470::getparam_alareen(int machine){
	return getparam(machine, 0x17,1);
}

long L6470::getparam_config(int machine){
	return getparam(machine, 0x18,2);
}

long L6470::getparam_status(int machine){
	return getparam(machine, 0x19,2);
}


////////////各動作のメソッド////////////

void L6470::L6470_setup(int machine){
	setparam_acc(machine, 0x30); //[R, WS] 加速度default 0x08A (12bit) (14.55*val+14.55[step/s^2])
	setparam_dec(machine, 0x30); //[R, WS] 減速度default 0x08A (12bit) (14.55*val+14.55[step/s^2])
	setparam_maxspeed(machine, 0x2a); //[R, WR]最大速度default 0x041 (10bit) (15.25*val+15.25[step/s])
	setparam_minspeed(machine, 0x1200); //[R, WS]最小速度default 0x000 (1+12bit) (0.238*val[step/s])
	setparam_fsspd(machine, 0x027); //[R, WR]μステップからフルステップへの切替点速度default 0x027 (10bit) (15.25*val+7.63[step/s])
	setparam_kvalhold(machine, 0x28); //[R, WR]停止時励磁電圧default 0x29 (8bit) (Vs[V]*val/256)
	setparam_kvalrun(machine, 0x28); //[R, WR]定速回転時励磁電圧default 0x29 (8bit) (Vs[V]*val/256)
	setparam_kvalacc(machine, 0x28); //[R, WR]加速時励磁電圧default 0x29 (8bit) (Vs[V]*val/256)
	setparam_kvaldec(machine, 0x28); //[R, WR]減速時励磁電圧default 0x29 (8bit) (Vs[V]*val/256)
	setparam_stepmood(machine, 0x02); //ステップモードdefault 0x07 (1+3+1+3bit)
}

void L6470::run(int machine, int dia,long spd){
  if(dia==1)
    transfer(machine, 0x51,3,spd);
  else
    transfer(machine, 0x50,3,spd);
}

void L6470::stepclock(int machine, int dia){
  if(dia==1)
    transfer(machine,0x59,0,0);    
  else
    transfer(machine,0x58,0,0);
}

void L6470::move(int machine, int dia,long n_step){
  if(dia==1)
    transfer(machine, 0x41,3,n_step);
  else
    transfer(machine, 0x40,3,n_step);
}

void L6470::goTo(int machine, long pos){
  transfer(machine, 0x60,3,pos);
}

void L6470::gotodia(int machine, int dia,int pos){
  if(dia==1)    
    transfer(machine, 0x69,3,pos);
  else    
    transfer(machine, 0x68,3,pos);
}

void L6470::gountil(int machine, int act,int dia,long spd){
  if(act==1)
    if(dia==1)
      transfer(machine, 0x8b,3,spd);
    else
      transfer(machine, 0x8a,3,spd);
  else
    if(dia==1)
      transfer(machine, 0x83,3,spd);
    else
      transfer(machine, 0x82,3,spd);
}  

void L6470::relesesw(int machine, int act,int dia){
  if(act==1)
    if(dia==1)
      transfer(machine, 0x9b,0,0);
    else
      transfer(machine, 0x9a,0,0);
  else
    if(dia==1)
      transfer(machine, 0x93,0,0);
    else
      transfer(machine, 0x92,0,0);
}

void L6470::gohome(int machine){
  transfer(machine, 0x70,0,0);
}

void L6470::gomark(int machine){
  transfer(machine, 0x78,0,0);
}

void L6470::resetpos(int machine){
  transfer(machine, 0xd8,0,0);
}
void L6470::resetdevice(int machine){
  send(machine, 0x00);//nop命令
  send(machine, 0x00);
  send(machine, 0x00);
  send(machine, 0x00);
  send(machine, 0xc0);
}
void L6470::softstop(int machine){
  transfer(machine, 0xb0,0,0);
}
void L6470::hardstop(int machine){
  transfer(machine, 0xb8,0,0);
}
void L6470::softhiz(int machine){
  transfer(machine, 0xa0,0,0);
}
void L6470::hardhiz(int machine){
  transfer(machine, 0xa8,0,0);
}

long L6470::getstatus(int machine){
  long val=0;
  send(machine, 0xd0);
  for(int i=0;i<=1;i++){
    val = val << 8;
    digitalWrite(spi_ss_pin, LOW); // ~SSイネーブル。
    if(machine != 2) {
      SPI.transfer(0x00); // アドレスもしくはデータ送信。
      val = val | SPI.transfer(0x00); // アドレスもしくはデータ送信。
    } else {
      val = val | SPI.transfer(0x00); // アドレスもしくはデータ送信。
      SPI.transfer(0x00); // アドレスもしくはデータ送信。
    }
    digitalWrite(spi_ss_pin, HIGH); // ~SSディスエーブル 
  }
  return val;
}

//-----
void L6470::transfer(int machine, int add,int bytes,long val){//1台目に送信
  int data[3];
  //while(!busy_flag()){} //BESYフラグが解除されるまで待機
  while(!digitalRead(busy_pin)){}//BESYピン出力が解除されるまで待機
  send(machine, add);
  for(int i=0;i<=bytes-1;i++){
    data[i] = val & 0xff;  
    val = val >> 8;
  }
  if(bytes==3){
    send(machine, data[2]);
  }
  if(bytes>=2){
    send(machine, data[1]);
  }
  if(bytes>=1){
    send(machine, data[0]);
  }  
}


void L6470::send(int machine, unsigned char add_or_val){
  digitalWrite(spi_ss_pin, LOW); // ~SSイネーブル。
  if(machine != 2) { //一台目なら
    SPI.transfer(0); // アドレスもしくはデータ送信。
    SPI.transfer(add_or_val); // アドレスもしくはデータ送信。
  } else { //二台目なら
    SPI.transfer(add_or_val); // アドレスもしくはデータ送信。
    SPI.transfer(0); // アドレスもしくはデータ送信。
  }
  digitalWrite(spi_ss_pin, HIGH); // ~SSディスエーブル。
}

void L6470::busydelay(long time){
//while(!busy_flag()){}
  while(!digitalRead(busy_pin)){}//BESYピン出力が解除されるまで待機
  delay(time);
}

int L6470::busy_flag(int machine
  ){
int sta = getparam_status(machine);
sta = sta >> 1;
sta = sta & 0x0001;
return sta;
 }