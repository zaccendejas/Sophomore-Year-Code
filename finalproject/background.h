// Zac Cendejas & Noelle Rosa
// 12/14/2016

class Background{//The Background class basically draws a mountain range the length of two windows and starts with the left edge of the range at the left edge of the window. When the move background is called the image is moved to the left pixel by pixel giving the impression that the background is slowly passing by. When the left edge of the mountain range reaches the negative of the width of the window, almost the entirety of the second mountain range has take its place and then the picture is reset to where it started in the window.   
	public:
		Background();
		~Background();
		void drawBackground();
		void moveBackground();
		void resetBackground();
		int getEnd();

	private:
		//used to set the color of the mountain
		int MountainR = 120;
		int MountainG = 0;
		int MountainB = 120;

		//used to set the color of the snow
		int SnowR = 255;
		int SnowG = 255;
		int SnowB = 255;

		int Xval = 0;

		// Variables used to draw mountains (There are six variables per mountain... left x, left y, top x, top y, and right x, as well as bottom y
		int Mnt1LX = 400;
		int Mnt1LY = 400;
		int Mnt1TX = 600;
		int Mnt1TY = 50;
		int Mnt1RX = 800;
		int Mnt1RY = 400;
		int Mnt2LX = 760;
		int Mnt2LY = 330;
		int Mnt2TX = 880;
		int Mnt2TY = 120;
		int Mnt2RX = 1000;
		int Mnt2RY = 400;
		int Mnt3LX = 680;
		int Mnt3LY = 190;
		int Mnt3TX = 720;
		int Mnt3TY = 120;
		int Mnt3RX = 820;
		int Mnt3RY = 225;
		int Mnt4LX = 1000;
		int Mnt4LY = 400;
		int Mnt4TX = 1160;
		int Mnt4TY = 120;
		int Mnt4RX = 1320;
		int Mnt4RY = 400;
		int Mnt5LX = 940;
		int Mnt5LY = 260;
		int Mnt5TX = 972;
		int Mnt5TY = 204;
		int Mnt5RX = 1040;
		int Mnt5RY = 330;
		int Mnt6LX = 400;
		int Mnt6LY = 400;
		int Mnt6TX = 300;
		int Mnt6TY = 225;
		int Mnt6RX = 200;
		int Mnt6RY = 400;
		int Mnt7LX = 320;
		int Mnt7LY = 260;
		int Mnt7TX = 400;
		int Mnt7TY = 100;
		int Mnt7RX = 480;
		int Mnt7RY = 260;
		int Mnt8LX = 200;
		int Mnt8LY = 400;
		int Mnt8TX = 20;
		int Mnt8TY = 85;
		int Mnt8RX = -20;
		int Mnt8RY = 150;
	
		//Variables for second round of mountains (the ones that start outside of the window)
		int Mnt11LX = 1600;
		int Mnt11LY = 400;
		int Mnt11TX = 1800;
		int Mnt11TY = 50;
		int Mnt11RX = 2000;
		int Mnt11RY = 400;
		int Mnt21LX = 1960;
		int Mnt21LY = 330;
		int Mnt21TX = 2080;
		int Mnt21TY = 120;
		int Mnt21RX = 2200;
		int Mnt21RY = 400;
		int Mnt31LX = 1880;
		int Mnt31LY = 190;
		int Mnt31TX = 1920;
		int Mnt31TY = 120;
		int Mnt31RX = 2020;
		int Mnt31RY = 225;
		int Mnt41LX = 2200;
		int Mnt41LY = 400;
		int Mnt41TX = 2360;
		int Mnt41TY = 120;
		int Mnt41RX = 2520;
		int Mnt41RY = 400;
		int Mnt51LX = 2140;
		int Mnt51LY = 260;
		int Mnt51TX = 2172;
		int Mnt51TY = 204;
		int Mnt51RX = 2240;
		int Mnt51RY = 330;
		int Mnt61LX = 1600;
		int Mnt61LY = 400;
		int Mnt61TX = 1500;
		int Mnt61TY = 225;
		int Mnt61RX = 1400;
		int Mnt61RY = 400;
		int Mnt71LX = 1520;
		int Mnt71LY = 260;
		int Mnt71TX = 1600;
		int Mnt71TY = 100;
		int Mnt71RX = 1680;
		int Mnt71RY = 260;
		int Mnt81LX = 1400;
		int Mnt81LY = 400;
		int Mnt81TX = 1220;
		int Mnt81TY = 85;
		int Mnt81RX = 1180;
		int Mnt81RY = 150;
		// Variables used to draw snow... The XPoint class takes in an array of points that are ultimately used to create the polygons that make the snow at the top of the mountains
		XPoint mypts1[6] = { {557, 125},{600,50},{658,150},{610,115},{575,140},{557,125} };
		XPoint mypts2[6] = { {835, 200},{880,120},{905,175},{900,165},{860,230},{835,200} };
		XPoint mypts3[6] ={ {700,155}, {720,120}, {765, 165}, {750,200},{710, 148}, {700, 155} };
		XPoint mypts4[5] ={ {1100,225},{1160,120},{1200,190}, {1170, 180}, {1100, 225} };
		XPoint mypts5[5] ={ {950,245},{972,204}, {1021,295}, {964, 225}, {950, 245} };
		XPoint mypts6[6] ={ {222,360},{300,225},{352,315}, {325, 280}, {290,270}, {222, 360} };
		XPoint mypts7[6] ={ {345,210},{400,100},{450,200}, {430, 180}, {375,230}, {345, 210} };
		XPoint mypts8[6] ={ {142,300}, {20,85},{0,120}, {0,225}, {35, 195}, {142,300} };

		//Points for snow on second round of mountains
		XPoint mypts11[6] ={ {1757,125},{1800,50},{1858,150}, {1810, 115}, {1775,140}, {1757, 125} };
		XPoint mypts21[6] ={ {2035,200},{2080,120},{2105,175}, {2100, 165}, {2060,230}, {2035, 200} };
		XPoint mypts31[6] ={ {1900,155}, {1920,120}, {1965, 165}, {1950,200},{1910, 148}, {1900, 155} };
		XPoint mypts41[5] ={ {2300,225},{2360,120},{2400,190}, {2370, 180}, {2300, 225} };
		XPoint mypts51[5] ={ {2150,245},{2172,204}, {2221,295}, {2164, 225}, {2150, 245} };
		XPoint mypts61[6] ={ {1422,360},{1500,225},{1552,315}, {1525, 280}, {1490,270}, {1422, 360} };
		XPoint mypts71[6] ={ {1545,210},{1600,100},{1650,200}, {1630, 180}, {1575,230}, {1545, 210} };
		XPoint mypts81[6] ={ {1342,300}, {1220,85},{1200,120}, {1188,147}, {1235, 195}, {1342,300} };
		int sz1 = sizeof(mypts1)/sizeof(XPoint);
		int sz2 = sizeof(mypts2)/sizeof(XPoint);
		int sz3 = sizeof(mypts3)/sizeof(XPoint);
		int sz4 = sizeof(mypts4)/sizeof(XPoint);
		int sz5 = sizeof(mypts5)/sizeof(XPoint);
		int sz6 = sizeof(mypts6)/sizeof(XPoint);
		int sz7 = sizeof(mypts7)/sizeof(XPoint);
		int sz8 = sizeof(mypts8)/sizeof(XPoint);
		int sz11 = sizeof(mypts11)/sizeof(XPoint);
		int sz21 = sizeof(mypts21)/sizeof(XPoint);
		int sz31 = sizeof(mypts31)/sizeof(XPoint);
		int sz41 = sizeof(mypts41)/sizeof(XPoint);
		int sz51 = sizeof(mypts51)/sizeof(XPoint);
		int sz61 = sizeof(mypts61)/sizeof(XPoint);
		int sz71 = sizeof(mypts71)/sizeof(XPoint);
		int sz81 = sizeof(mypts81)/sizeof(XPoint);
		
};





