#include<io.h>


int sin[91] =  //格式 : 低8位的最高位为整数,尾数为小数
{

0x00, //sin(0) = 0 无误差
0x02, //sin(1) = 0.0174524,这里取值0.015625
0x04, //sin(2) = 0.0348995,这里取值0.03125
0x07, //sin(3) = 0.052336,这里取值0.0546875
0x09, //sin(4) = 0.0697565,这里取值0.0703125
0x0b, //sin(5) = 0.0871557,这里取值0.0859375
0x0d, //sin(6) = 0.1045285,这里取值0.1015625
0x10, //sin(7) = 0.1218693,这里取值0.125
0x12, //sin(8) = 0.1391731,这里取值0.140625
0x14, //sin(9) = 0.1564344,这里取值0.15625
0x16, //sin(10) = 0.1736482,这里取值0.171875
0x18, //sin(11) = 0.190809,这里取值0.1875
0x1b, //sin(12) = 0.2079117,这里取值0.2109375
0x1d, //sin(13) = 0.2249511,这里取值0.2265625
0x1f, //sin(14) = 0.2419219,这里取值0.2421875
0x21, //sin(15) = 0.258819,这里取值0.2578125
0x23, //sin(16) = 0.2756374,这里取值0.2734375
0x25, //sin(17) = 0.2923717,这里取值0.2890625
0x28, //sin(18) = 0.309017,这里取值0.3125
0x2a, //sin(19) = 0.3255682,这里取值0.328125
0x2c, //sin(20) = 0.3420201,这里取值0.34375
0x2e, //sin(21) = 0.3583679,这里取值0.359375
0x30, //sin(22) = 0.3746066,这里取值0.375
0x32, //sin(23) = 0.3907311,这里取值0.390625
0x34, //sin(24) = 0.4067366,这里取值0.40625
0x36, //sin(25) = 0.4226183,这里取值0.421875
0x38, //sin(26) = 0.4383711,这里取值0.4375
0x3a, //sin(27) = 0.4539905,这里取值0.453125
0x3c, //sin(28) = 0.4694716,这里取值0.46875
0x3e, //sin(29) = 0.4848096,这里取值0.484375
0x40, //sin(30) = 0.5, 无误差
0x42, //sin(31) = 0.5150381,这里取值0.515625
0x44, //sin(32) = 0.5299193,这里取值0.53125
0x46, //sin(33) = 0.544639,这里取值0.546875
0x48, //sin(34) = 0.5591929,这里取值0.5625
0x49, //sin(35) = 0.5735764,这里取值0.5703125
0x4b, //sin(36) = 0.5877852,这里取值0.5859375
0x4d, //sin(37) = 0.601815,这里取值0.6015625
0x4f, //sin(38) = 0.6156615,这里取值0.6171875
0x51, //sin(39) = 0.6293204,这里取值0.6328125
0x52, //sin(40) = 0.6427876,这里取值0.640625
0x54, //sin(41) = 0.656059,这里取值0.65625
0x56, //sin(42) = 0.6691306,这里取值0.671875
0x57, //sin(43) = 0.6819984,这里取值0.6796875
0x59, //sin(44) = 0.6946584,这里取值0.6953125
0x5a, //sin(45) = 0.7071068,这里取值0.7109375
0x5c, //sin(46) = 0.7193398,这里取值0.71875
0x5e, //sin(47) = 0.7313537,这里取值0.734375
0x5f, //sin(48) = 0.7431448,这里取值0.7421875
0x61, //sin(49) = 0.7547096,这里取值0.7578125
0x62, //sin(50) = 0.7660444,这里取值0.765625
0x63, //sin(51) = 0.777146,这里取值0.7734375
0x65, //sin(52) = 0.7880108,这里取值0.7890625
0x66, //sin(53) = 0.7986355,这里取值0.796875
0x68, //sin(54) = 0.809017,这里取值0.8125
0x69, //sin(55) = 0.819152,这里取值0.8203125
0x6a, //sin(56) = 0.8290376,这里取值0.828125
0x6b, //sin(57) = 0.838671,这里取值0.8359375
0x6d, //sin(58) = 0.8480481,这里取值0.8515625
0x6e, //sin(59) = 0.8571673,这里取值0.859375
0x6f, //sin(60) = 0.8660254,这里取值0.8671875
0x70, //sin(61) = 0.8746197,这里取值0.875
0x71, //sin(62) = 0.8829476,这里取值0.8828125
0x72, //sin(63) = 0.8910065,这里取值0.890625
0x73, //sin(64) = 0.8987941,这里取值0.8984375
0x74, //sin(65) = 0.9063078,这里取值0.90625
0x75, //sin(66) = 0.9135455,这里取值0.9140625
0x76, //sin(67) = 0.9205049,这里取值0.921875
0x77, //sin(68) = 0.9271839,这里取值0.9296875
0x78, //sin(69) = 0.9335804,这里取值0.9375
0x78, //sin(70) = 0.9396926,这里取值0.9375
0x79, //sin(71) = 0.9455186,这里取值0.9453125
0x7a, //sin(72) = 0.9510565,这里取值0.953125
0x7a, //sin(73) = 0.9563048,这里取值0.953125
0x7b, //sin(74) = 0.9612617,这里取值0.9609375
0x7c, //sin(75) = 0.9659258,这里取值0.96875
0x7c, //sin(76) = 0.9702957,这里取值0.96875
0x7d, //sin(77) = 0.9743701,这里取值0.9765625
0x7d, //sin(78) = 0.9781476,这里取值0.9765625
0x7e, //sin(79) = 0.9816272,这里取值0.984375
0x7e, //sin(80) = 0.9848078,这里取值0.984375
0x7e, //sin(81) = 0.9876883,这里取值0.984375
0x7f, //sin(82) = 0.9902681,这里取值0.9921875
0x7f, //sin(83) = 0.9925462,这里取值0.9921875
0x7f, //sin(84) = 0.9945219,这里取值0.9921875
0x7f, //sin(85) = 0.9961947,这里取值0.9921875
0x80, //sin(86) = 0.9975641,这里取值1
0x80, //sin(87) = 0.9984295,这里取值1
0x80, //sin(88) = 0.9993908,这里取值1
0x80, //sin(89) = 0.9998477,这里取值1
0x80  //sin(90) = 1,这里取值1
};




int sin_360[361];
int cos_360[361];
char MUL_H,MUL_L;

@0x020000 char MUL_DL[65536],MUL_DH[65536];@

void MUL_csh()
{
   unsigned int a = 0;

   do MUL_DL[a] = ((a >> 8) & 0x00ff) * (a & 0x00ff),++a; while(a != 0);
   do MUL_DH[a] = ((a >> 8) & 0x00ff) * (a & 0x00ff) >> 8,++a; while(a != 0);

}


MUL_16(int a,int b)
{

   int i;


   unsigned char a_h,a_l;
   unsigned char b_h,b_l;

   unsigned char albl_H,albl_L,albh_H,ahbl_H;

   a_h = a >> 8;
   a_l = a;
   b_h = b >> 8;
   b_l = b;

   _A = a_l;
   _A0 = b_l;
   _A2 = 0x02;
   _A1 = _A;
   _NOP;
   _A = _RAM;
   albl_L = _A;

   _A = a_l;
   _A0 = b_l;
   _A2 = 0x03;
   _A1 = _A;
   _NOP;
   _A = _RAM;
   albl_H = _A;

   _A = a_l;
   _A0 = b_h;
   _A2 = 0x02;
   _A1 = _A;
   _NOP;
   _A = _RAM;
   albh_H = _A;

   _A = a_h;
   _A0 = b_l;
   _A2 = 0x02;
   _A1 = _A;
   _NOP;
   _A = _RAM;
   ahbl_H = _A;


   i = albl_H;
   i += albh_H;
   i += ahbl_H;
   i <<= 8;
   i += albl_L;

   return i;
   
}


void sin_cos_csh()
{

 unsigned int D = 0;

 while(D != 361)
 {

   if(D < 91) //角度为0到90度 取出sin值和cos值
   {
      sin_360[D] = sin[D];
      cos_360[D] = sin[90 - D];
   }
   else if(D > 90 && D < 181) //角度为91到180度 取出sin值和cos值
   {
      sin_360[D] = sin[180 - D];
      cos_360[D] = -sin[D - 90];
   }
   else if(D > 180 && D < 271) //角度为181到270度 取出sin值和cos值
   {
      sin_360[D] = -sin[D - 180];
      cos_360[D] = -sin[270 - D];
   }
   else //角度为271到360度 取出sin值和cos值
   {
      sin_360[D] = -sin[360 - D];
      cos_360[D] = sin[D - 270];
   }

   ++D;

 }

}



void yuan(VRAMY,VRAMX,XD,YD,ZD,r,VRAM_DATA)
{

   int dd = 0,Y,X,Z,y,x,_sin,_cos;
   int _Y,_X,_Z;
   int _sin1,_cos1;
   int _sin2,_cos2;
   int _sin3,_cos3;

      _sin1 = sin_360[XD];
      _cos1 = cos_360[XD];

      _sin2 = sin_360[YD];
      _cos2 = cos_360[YD];

      _sin3 = sin_360[ZD];
      _cos3 = cos_360[ZD];

   do
   {
/*
      _sin = sin_360[dd];
      _cos = cos_360[dd];
      X = _cos*r >> 7;
      _Y = _sin*r >> 7;

      _sin = sin_360[XD];
      _cos = cos_360[XD];
      Y = _cos*_Y >> 7;
      _Z = _sin*_Y >> 7;

      _sin = sin_360[YD];
      _cos = cos_360[YD];
 //     Z = _cos*_Z - _sin*X >> 7;
      _X = _sin*_Z + _cos*X >> 7;

      _sin = sin_360[ZD];
      _cos = cos_360[ZD];
      X = _cos*_X - _sin*Y >> 7;
      Y = _sin*_X + _cos*Y >> 7;
*/


      _sin = sin_360[dd];
      _cos = cos_360[dd];
      X = MUL_16(_cos,r) >> 7;
      _Y = MUL_16(_sin,r) >> 7;


      Y = MUL_16(_cos1,_Y) >> 7;
      _Z = MUL_16(_sin1,_Y) >> 7;


 //     Z = MUL_16(_cos2,_Z) - MUL_16(_sin2,X) >> 7;
      _X = MUL_16(_sin2,_Z) + MUL_16(_cos2,X) >> 7;


      X = MUL_16(_cos3,_X) - MUL_16(_sin3,Y) >> 7;
      Y = MUL_16(_sin3,_X) + MUL_16(_cos3,Y) >> 7;


      y = VRAMY - Y; //转换为实际坐标
      x = VRAMX + X;

      VRAM[(y << 8) | (x & 0x00ff)] = VRAM_DATA; //写入显存

      dd += 10;

   }while(dd < 360);

}


void guidaoyuan(VRAMY,VRAMX,XD,YD,ZD,r,rr,rrD,VRAM_DATA)
{

   int dd = 0,Y,X,Z,y,x,_sin,_cos;
   int _Y,_X,_Z;
   int _sin1,_cos1;
   int _sin2,_cos2;
   int _sin3,_cos3;
   int _sin4,_cos4;

      _sin1 = sin_360[XD];
      _cos1 = cos_360[XD];

      _sin2 = sin_360[YD];
      _cos2 = cos_360[YD];

      _sin3 = sin_360[ZD];
      _cos3 = cos_360[ZD];

      _sin4 = sin_360[rrD];
      _cos4 = cos_360[rrD];


   do
   {

      _sin = sin_360[dd];
      _cos = cos_360[dd];
      Z = MUL_16(_cos,rr)  >> 7;
      _X = MUL_16(_sin,rr)  >> 7;


      X = MUL_16(_cos4,r+_X)  >> 7;
      _Y = MUL_16(_sin4,r+_X)  >> 7;


      Y = MUL_16(_cos1,_Y) - MUL_16(_sin1,Z) >> 7;
      _Z = MUL_16(_sin1,_Y) + MUL_16(_cos1,Z) >> 7;


      //Z = MUL_16(_cos2,_Z) - MUL_16(_sin2,X) >> 7;
      _X = MUL_16(_sin2,_Z) + MUL_16(_cos2,X) >> 7;


      X = MUL_16(_cos3,_X) - MUL_16(_sin3,Y) >> 7;
      Y = MUL_16(_sin3,_X) + MUL_16(_cos3,Y) >> 7;


      y = VRAMY - Y; //转换为实际坐标
      x = VRAMX + X;

      VRAM[(y << 8) | (x & 0x00ff)] = VRAM_DATA;

      dd += 40;

   }while(dd < 360);

}


void VRAM_qingping(unsigned char Y,unsigned char _Y,unsigned char DATA)
{


 while(Y != _Y)
 {

   _B = DATA;
   _A = 0;

   do
   {
     _A1 = Y;
     _A2 = 0x80;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

     _A0 = _A;
     _NOP;
     _RAM = _B;
     _A = _A + 1;

   }while(_SUB_A_1 != -1);

   ++Y;

 }


}



void zhongxinzhou(VRAMY,VRAMX,XD,YD,ZD,VRAM_DATA)
{


   int zz = -32,Y,X,Z,y,x,_sin,_cos;
   int _Y,_X,_Z;

   int _sin1,_cos1;
   int _sin2,_cos2;
   int _sin3,_cos3;


      _sin1 = sin_360[XD];
      _cos1 = cos_360[XD];

      _sin2 = sin_360[YD];
      _cos2 = cos_360[YD];

      _sin3 = sin_360[ZD];
      _cos3 = cos_360[ZD];


   do
   {


      Y = - MUL_16(_sin1,zz) >> 7;
      _Z =  MUL_16(_cos1,zz) >> 7;


 //     Z = MUL_16(_cos2,_Z) >> 7;
      _X = MUL_16(_sin2,_Z) >> 7;


      X = MUL_16(_cos3,_X) - MUL_16(_sin3,Y) >> 7;
      Y = MUL_16(_sin3,_X) + MUL_16(_cos3,Y) >> 7; 


      y = VRAMY - Y; //转换为实际坐标
      x = VRAMX + X;

      VRAM[(y << 8) | (x & 0x00ff)] = VRAM_DATA; //写入显存

      zz += 4;

   }while(zz < 32);





}



main()
{

   int i,YD = 0,XD = 0,ZD = 0,gdhwz1 = 0,gdhwz2 = 360,k = 0;
   int YD1 = 0,XD1 = 0,ZD1 = 0;

   CTVGA_C &= ~0x01; //请求访问VRAM
   while((CTVGA_C & 0x80) == 0x80); //可以访问的时候跳出
   VRAM_qingping(0,240,0x00);
   CTVGA_C |= 0x01; //请求VRAM显示
   for(i = 0;i != 25000;++i);

   sin_cos_csh();
   MUL_csh();

   while(1)
   {

      CTVGA_C &= ~0x01; //请求访问VRAM
      while((CTVGA_C & 0x80) == 0x80); //可以访问的时候跳出

      VRAM_qingping(120 - 106,120 + 106,0x00);


    //  ++YD;
   //   ++YD;
   //   if(YD == 360) YD = 0;

//if((INT_8080 & 0x02) == 0x00)
//{

      ++XD;
      ++XD;
      ++XD;
      if(XD == 360) XD = 0;
      ++ZD;
      if(ZD == 360) ZD = 0;
//}

      gdhwz1 +=4;
      if(gdhwz1 == 360) gdhwz1 = 0,k = ~k;
      gdhwz2 -=8;
      if(gdhwz2 == 0) gdhwz2 = 360;
/*
if((INT_8080 & 0x01) == 0x01)
{
      ++ZD1;
      ++ZD1;
      ++ZD1;
      if(ZD1 == 360) ZD1 = 0;
      ++YD1;
      if(YD1 == 360) YD1 = 0;
}

*/


      zhongxinzhou(120,128,XD,YD,ZD,0x1f);

      if(k == 0) yuan(120,128,XD,YD,ZD,32,0x03);

      guidaoyuan(120,128,XD,YD,ZD,32,5,gdhwz2,0x1c);

      yuan(120,128,XD,YD,ZD,64,0xe0);
      if(k == 0)
      yuan(120,128,XD,YD,ZD,80,0x13),
      yuan(120,128,XD,YD,ZD,96,0xe5);

      guidaoyuan(120,128,XD,YD,ZD,96,5,gdhwz1,0x96);


      CTVGA_C |= 0x01; //请求VRAM显示
      for(i = 0;i != 7000;++i);

   }


}






