#include "l6470.h"


//コンストラクタ：初期化
L6470::L6470(int mosi, int miso, int sck, int ss, int busy)
: spi_mosi_pin(mosi), spi_miso_pin(miso), spi_sck_pin(sck), spi_ss_pin(ss), busy_pin(busy) {}


//各値をセットするメソッド
void L6470::setparam_abspos(long val){
	transfer(0x01,3,val);
}

void L6470::setparam_elpos(long val){
	transfer(0x02,2,val);
}

void L6470::setparam_mark(long val){
	transfer(0x03,3,val);
}

void L6470::setparam_acc(long val){
	transfer(0x05,2,val);
}

void L6470::setparam_dec(long val){
	transfer(0x06,2,val);
}

void L6470::setparam_maxspeed(long val){
	transfer(0x07,2,val);
}

void L6470::setparam_minspeed(long val){
	transfer(0x08,2,val);
}

void L6470::setparam_fsspd(long val){
	transfer(0x15,2,val);
}

void L6470::setparam_kvalhold(long val){
	transfer(0x09,1,val);
}

void L6470::setparam_kvalrun(long val){
	transfer(0x0a,1,val);
}

void L6470::setparam_kvalacc(long val){
	transfer(0x0b,1,val);
}

void L6470::setparam_kvaldec(long val){
	transfer(0x0c,1,val);
}

void L6470::setparam_intspd(long val){
	transfer(0x0d,2,val);
}

void L6470::setparam_stslp(long val){
	transfer(0x0e,1,val);
}

void L6470::setparam_fnslpacc(long val){
	transfer(0x0f,1,val);
}

void L6470::setparam_fnslpdec(long val){
	transfer(0x10,1,val);
}

void L6470::setparam_ktherm(long val){
	transfer(0x11,1,val);
}

void L6470::setparam_ocdth(long val){
	transfer(0x13,1,val);
}

void L6470::setparam_stallth(long val){
	transfer(0x14,1,val);
}

void L6470::setparam_stepmood(long val){
	transfer(0x16,1,val);
}

void L6470::setparam_alareen(long val){
	transfer(0x17,1,val);
}

void L6470::setparam_config(long val){
	transfer(0x18,2,val);
}

//各値を取得するメソッド
long L6470::getparam(int add, int bytes){//1台目に送信
  long val=0;
  int send_add = add | 0x20;
  send(send_add);
  for(int i=0;i<=bytes-1;i++){
    val = val << 8;
    digitalWrite(spi_ss_pin, LOW); // ~SSイネーブル。
    SPI.transfer(0x00);// 0送信。
    val = val | SPI.transfer(0x00); // アドレスもしくはデータ送信。
    digitalWrite(spi_ss_pin, HIGH); // ~SSディスエーブル 
  }
  return val;
}

long L6470::getparam_abspos(){
	return getparam(0x01,3);
}

long L6470::getparam_elpos(){
	return getparam(0x02,2);
}

long L6470::getparam_mark(){
	return getparam(0x03,3);
}

long L6470::getparam_speed(){
	return getparam(0x04,3);
}

long L6470::getparam_acc(){
	return getparam(0x05,2);
}

long L6470::getparam_dec(){
	return getparam(0x06,2);
}

long L6470::getparam_maxspeed(){
	return getparam(0x07,2);
}

long L6470::getparam_minspeed(){
	return getparam(0x08,2);
}

long L6470::getparam_fsspd(){
	return getparam(0x15,2);
}

long L6470::getparam_kvalhold(){
	return getparam(0x09,1);
}

long L6470::getparam_kvalrun(){
	return getparam(0x0a,1);
}

long L6470::getparam_kvalacc(){
	return getparam(0x0b,1);
}

long L6470::getparam_kvaldec(){
	return getparam(0x0c,1);
}

long L6470::getparam_intspd(){
	return getparam(0x0d,2);
}

long L6470::getparam_stslp(){
	return getparam(0x0e,1);
}

long L6470::getparam_fnslpacc(){
	return getparam(0x0f,1);
}

long L6470::getparam_fnslpdec(){
	return getparam(0x10,1);
}

long L6470::getparam_ktherm(){
	return getparam(0x11,1);
}

long L6470::getparam_adcout(){
	return getparam(0x12,1);
}

long L6470::getparam_ocdth(){
	return getparam(0x13,1);
}

long L6470::getparam_stallth(){
	return getparam(0x14,1);
}

long L6470::getparam_stepmood(){
	return getparam(0x16,1);
}

long L6470::getparam_alareen(){
	return getparam(0x17,1);
}

long L6470::getparam_config(){
	return getparam(0x18,2);
}

long L6470::getparam_status(){
	return getparam(0x19,2);
}


////////////各動作のメソッド////////////

void L6470::L6470_setup(){
	setparam_acc(0x30); //[R, WS] 加速度default 0x08A (12bit) (14.55*val+14.55[step/s^2])
	setparam_dec(0x30); //[R, WS] 減速度default 0x08A (12bit) (14.55*val+14.55[step/s^2])
	setparam_maxspeed(0x2a); //[R, WR]最大速度default 0x041 (10bit) (15.25*val+15.25[step/s])
	setparam_minspeed(0x1200); //[R, WS]最小速度default 0x000 (1+12bit) (0.238*val[step/s])
	setparam_fsspd(0x027); //[R, WR]μステップからフルステップへの切替点速度default 0x027 (10bit) (15.25*val+7.63[step/s])
	setparam_kvalhold(0x28); //[R, WR]停止時励磁電圧default 0x29 (8bit) (Vs[V]*val/256)
	setparam_kvalrun(0x28); //[R, WR]定速回転時励磁電圧default 0x29 (8bit) (Vs[V]*val/256)
	setparam_kvalacc(0x28); //[R, WR]加速時励磁電圧default 0x29 (8bit) (Vs[V]*val/256)
	setparam_kvaldec(0x28); //[R, WR]減速時励磁電圧default 0x29 (8bit) (Vs[V]*val/256)
	setparam_stepmood(0x02); //ステップモードdefault 0x07 (1+3+1+3bit)
}

void L6470::run(int dia,long spd){
  if(dia==1)
    transfer(0x51,3,spd);
  else
    transfer(0x50,3,spd);
}

void L6470::stepclock(int dia){
  if(dia==1)
    transfer(0x59,0,0);    
  else
    transfer(0x58,0,0);
}

void L6470::move(int dia,long n_step){
  if(dia==1)
    transfer(0x41,3,n_step);
  else
    transfer(0x40,3,n_step);
}

void L6470::goTo(long pos){
  transfer(0x60,3,pos);
}

void L6470::gotodia(int dia,int pos){
  if(dia==1)    
    transfer(0x69,3,pos);
  else    
    transfer(0x68,3,pos);
}

void L6470::gountil(int act,int dia,long spd){
  if(act==1)
    if(dia==1)
      transfer(0x8b,3,spd);
    else
      transfer(0x8a,3,spd);
  else
    if(dia==1)
      transfer(0x83,3,spd);
    else
      transfer(0x82,3,spd);
}  

void L6470::relesesw(int act,int dia){
  if(act==1)
    if(dia==1)
      transfer(0x9b,0,0);
    else
      transfer(0x9a,0,0);
  else
    if(dia==1)
      transfer(0x93,0,0);
    else
      transfer(0x92,0,0);
}

void L6470::gohome(){
  transfer(0x70,0,0);
}

void L6470::gomark(){
  transfer(0x78,0,0);
}

void L6470::resetpos(){
  transfer(0xd8,0,0);
}
void L6470::resetdevice(){
  send(0x00);//nop命令
  send(0x00);
  send(0x00);
  send(0x00);
  send(0xc0);
}
void L6470::softstop(){
  transfer(0xb0,0,0);
}
void L6470::hardstop(){
  transfer(0xb8,0,0);
}
void L6470::softhiz(){
  transfer(0xa0,0,0);
}
void L6470::hardhiz(){
  transfer(0xa8,0,0);
}

long L6470::getstatus(){
  long val=0;
  send(0xd0);
  for(int i=0;i<=1;i++){
    val = val << 8;
    digitalWrite(spi_ss_pin, LOW); // ~SSイネーブル。
    SPI.transfer(0x00); // アドレスもしくはデータ送信。
    val = val | SPI.transfer(0x00); // アドレスもしくはデータ送信。
    digitalWrite(spi_ss_pin, HIGH); // ~SSディスエーブル 
  }
  return val;
}

//-----
void L6470::transfer(int add,int bytes,long val){//1台目に送信
  int data[3];
  //while(!busy_flag()){} //BESYフラグが解除されるまで待機
  while(!digitalRead(busy_pin)){}//BESYピン出力が解除されるまで待機
  send(add);
  for(int i=0;i<=bytes-1;i++){
    data[i] = val & 0xff;  
    val = val >> 8;
  }
  if(bytes==3){
    send(data[2]);
  }
  if(bytes>=2){
    send(data[1]);
  }
  if(bytes>=1){
    send(data[0]);
  }  
}


void L6470::send(unsigned char add_or_val){//1台目に送信
  digitalWrite(spi_ss_pin, LOW); // ~SSイネーブル。
  SPI.transfer(0); // アドレスもしくはデータ送信。
  SPI.transfer(add_or_val); // アドレスもしくはデータ送信。
  digitalWrite(spi_ss_pin, HIGH); // ~SSディスエーブル。
}

void L6470::busydelay(long time){
//while(!busy_flag()){}
  while(!digitalRead(busy_pin)){}//BESYピン出力が解除されるまで待機
  delay(time);
}

int L6470::busy_flag(){
int sta = getparam_status();
sta = sta >> 1;
sta = sta & 0x0001;
return sta;
 }