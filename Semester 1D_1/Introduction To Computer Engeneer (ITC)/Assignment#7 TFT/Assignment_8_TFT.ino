#include <ST7735_TEE.h>

#define BUTTON_A 2

TEE_ST7735 lcd(9, 10, 11, 12, 13); //Arduino  csk,sda,A0,rst,cs

struct Game {
  // Variables
  short moveUP = 0;
  bool endGame = false;

  // Begin Floor
  struct Floor {
    byte x;
    byte y;
    byte width;
    byte height;
    word color;
  } Floor;
  // End Floor

  // Begin Bird
  struct Bird {
    byte x;
    byte y;
  } Bird;
  // End Bird

  // Begin Pilars
  struct Pilars {
    byte x;
    byte top;
    byte bottom;
    bool isPassed = false;
  } Pilar1;

  // Begin Score
  struct Score {
    byte     x;
    byte     y;
    unsigned value[2];
    word     color;
    byte     fontsize;
  } Score;
  // End Score

  // Functions
  void Init()
  {
    // Begin Background
    lcd.fillScreen(RGB(113, 197, 207));
    // End Background

    // Begin Floor
    Floor.x      = 0;
    Floor.y      = lcd.height - 25;
    Floor.width  = lcd.width;
    Floor.height = lcd.height - Floor.y;
    Floor.color  = RGB(221, 216, 148);
    // End Floor

    // Begin Bird
    Bird.x = 35;
    Bird.y = 50;
    // End Bird
    
    // Begin Pilars
    Pilar1.x = lcd.width - 30;
    Pilar1.top = random(30, lcd.height - Floor.height - 30);
    Pilar1.bottom = lcd.height - Floor.height - Pilar1.top - 30;
    // End Pilars

    // Begin Score Board
    Score.x        = 5;
    Score.y        = lcd.height - 15;
    Score.value[0] = 0;
    Score.value[1] = Score.value[0];
    Score.color    = BLACK;
    Score.fontsize = 1;
    // End Score Board

    setFloor();
    drawBird(Bird.x, Bird.y);
    drawPilars(Pilar1);
    showScore();
  }

  void Run()
  {
    bool changePos = false;

    if (!endGame)
    {
      if (Pilar1.x > 0)
      {
        Pilar1.x--;
        drawPilars(Pilar1);
      }

      if (Bird.x > Pilar1.x + 30 && !Pilar1.isPassed)
      {
        Pilar1.isPassed = true;
        Score.value[1]++;
      }
      
      if ( Score.value[0] != Score.value[1] )
      {
        Score.value[0] = Score.value[1];
        setFloor();
        showScore();
      }

      if (!digitalRead(BUTTON_A))
      {
        delay(50);
        moveUP += 5;
      }

      if (moveUP)
      {
        Bird.y--;
        moveUP--;
        changePos = true;
      }
      else if (Bird.y < 1.5 * Floor.y - 0.5 * lcd.height)
      {
        Bird.y++;
        changePos = true;
      }
      else
      {
        endGame = true;
      }

      if (Bird.x + 17 >= Pilar1.x && (Bird.x + 17 <= Pilar1.x + 30 || Bird.x <= Pilar1.x + 30))
      {
        if (Bird.y <= Pilar1.top || Bird.y + 12 >= Pilar1.top + 30)
        {
          endGame = true;
        }
      }

      if (endGame)
      {
        setFloor();
        showScore();
      }

      if (changePos)
      {
        drawBird(Bird.x, Bird.y);
      }
    }
  }

  void setFloor()
  {
    lcd.fillRect(Floor.x, Floor.y, Floor.width, Floor.height, Floor.color);
  }

  void drawBird(byte& x, byte& y)
  {
    lcd.drawPixel(x + 16, y + 10, RGB(113, 197, 207));

    lcd.drawPixel(x, y + 11, RGB(113, 197, 207));
    lcd.drawPixel(x + 15, y + 11, RGB(113, 197, 207));

    lcd.drawPixel(x + 1, y + 12, RGB(113, 197, 207));
    lcd.drawPixel(x + 2, y + 12, RGB(113, 197, 207));
    lcd.drawPixel(x + 3, y + 12, RGB(113, 197, 207));
    lcd.drawPixel(x + 4, y + 12, RGB(113, 197, 207));
    lcd.drawPixel(x + 10, y + 12, RGB(113, 197, 207));
    lcd.drawPixel(x + 11, y + 12, RGB(113, 197, 207));
    lcd.drawPixel(x + 12, y + 12, RGB(113, 197, 207));
    lcd.drawPixel(x + 13, y + 12, RGB(113, 197, 207));
    lcd.drawPixel(x + 14, y + 12, RGB(113, 197, 207));

    lcd.drawPixel(x + 5, y + 13, RGB(113, 197, 207));
    lcd.drawPixel(x + 6, y + 13, RGB(113, 197, 207));
    lcd.drawPixel(x + 7, y + 13, RGB(113, 197, 207));
    lcd.drawPixel(x + 8, y + 13, RGB(113, 197, 207));
    lcd.drawPixel(x + 9, y + 13, RGB(113, 197, 207));

    lcd.drawPixel(x + 6, y - 1, RGB(113, 197, 207));
    lcd.drawPixel(x + 7, y - 1, RGB(113, 197, 207));
    lcd.drawPixel(x + 8, y - 1, RGB(113, 197, 207));
    lcd.drawPixel(x + 9, y - 1, RGB(113, 197, 207));
    lcd.drawPixel(x + 10, y - 1, RGB(113, 197, 207));
    lcd.drawPixel(x + 11, y - 1, RGB(113, 197, 207));

    lcd.drawPixel(x + 4, y, RGB(113, 197, 207));
    lcd.drawPixel(x + 5, y, RGB(113, 197, 207));
    lcd.drawPixel(x + 12, y, RGB(113, 197, 207));

    lcd.drawPixel(x + 3, y + 1, RGB(113, 197, 207));
    lcd.drawPixel(x + 8, y + 1, RGB(113, 197, 207));
    lcd.drawPixel(x + 13, y + 1, RGB(113, 197, 207));

    lcd.drawPixel(x + 2, y + 2, RGB(113, 197, 207));
    lcd.drawPixel(x + 12, y + 2, RGB(113, 197, 207));
    lcd.drawPixel(x + 14, y + 2, RGB(113, 197, 207));

    lcd.drawPixel(x + 1, y + 3, RGB(113, 197, 207));

    lcd.drawPixel(x + 9, y + 4, RGB(113, 197, 207));

    lcd.drawPixel(x + 2, y + 5, RGB(113, 197, 207));
    lcd.drawPixel(x + 15, y + 5, RGB(113, 197, 207));

    lcd.drawPixel(x, y + 6, RGB(113, 197, 207));
    lcd.drawPixel(x + 16, y + 6, RGB(113, 197, 207));

    lcd.drawPixel(x + 6, y, RGB(95, 55, 79));
    lcd.drawPixel(x + 7, y, RGB(95, 55, 79));
    lcd.drawPixel(x + 8, y, RGB(95, 55, 79));
    lcd.drawPixel(x + 9, y, RGB(95, 55, 79));
    lcd.drawPixel(x + 10, y, RGB(95, 55, 79));
    lcd.drawPixel(x + 11, y, RGB(95, 55, 79));

    lcd.drawPixel(x + 4, y + 1, RGB(95, 55, 79));
    lcd.drawPixel(x + 5, y + 1, RGB(95, 55, 79));
    lcd.drawPixel(x + 6, y + 1, RGB(253, 214, 133));
    lcd.drawPixel(x + 7, y + 1, RGB(253, 214, 133));
    lcd.drawPixel(x + 8, y + 1, RGB(253, 214, 133));
    lcd.drawPixel(x + 9, y + 1, RGB(95, 55, 79));
    lcd.drawPixel(x + 10, y + 1, RGB(247, 253, 250));
    lcd.drawPixel(x + 11, y + 1, RGB(247, 253, 250));
    lcd.drawPixel(x + 12, y + 1, RGB(95, 55, 79));

    lcd.drawPixel(x + 3, y + 2, RGB(95, 55, 79));
    lcd.drawPixel(x + 4, y + 2, RGB(253, 214, 133));
    lcd.drawPixel(x + 5, y + 2, RGB(253, 214, 133));
    lcd.drawPixel(x + 6, y + 2, RGB(250, 185, 22));
    lcd.drawPixel(x + 7, y + 2, RGB(250, 185, 22));
    lcd.drawPixel(x + 8, y + 2, RGB(95, 55, 79));
    lcd.drawPixel(x + 9, y + 2, RGB(247, 253, 250));
    lcd.drawPixel(x + 10, y + 2, RGB(247, 253, 250));
    lcd.drawPixel(x + 11, y + 2, RGB(247, 253, 250));
    lcd.drawPixel(x + 12, y + 2, RGB(247, 253, 250));
    lcd.drawPixel(x + 13, y + 2, RGB(95, 55, 79));

    lcd.drawPixel(x + 2, y + 3, RGB(95, 55, 79));
    lcd.drawPixel(x + 3, y + 3, RGB(253, 214, 133));
    lcd.drawPixel(x + 4, y + 3, RGB(250, 185, 22));
    lcd.drawPixel(x + 5, y + 3, RGB(250, 185, 22));
    lcd.drawPixel(x + 6, y + 3, RGB(250, 185, 22));
    lcd.drawPixel(x + 7, y + 3, RGB(250, 185, 22));
    lcd.drawPixel(x + 8, y + 3, RGB(95, 55, 79));
    lcd.drawPixel(x + 9, y + 3, RGB(208, 230, 205));
    lcd.drawPixel(x + 10, y + 3, RGB(247, 253, 250));
    lcd.drawPixel(x + 11, y + 3, RGB(247, 253, 250));
    lcd.drawPixel(x + 12, y + 3, RGB(95, 55, 79));
    lcd.drawPixel(x + 13, y + 3, RGB(247, 253, 250));
    lcd.drawPixel(x + 14, y + 3, RGB(95, 55, 79));

    lcd.drawPixel(x + 1, y + 4, RGB(95, 55, 79));
    lcd.drawPixel(x + 2, y + 4, RGB(250, 185, 22));
    lcd.drawPixel(x + 3, y + 4, RGB(250, 185, 22));
    lcd.drawPixel(x + 4, y + 4, RGB(250, 185, 22));
    lcd.drawPixel(x + 5, y + 4, RGB(250, 185, 22));
    lcd.drawPixel(x + 6, y + 4, RGB(250, 185, 22));
    lcd.drawPixel(x + 7, y + 4, RGB(250, 185, 22));
    lcd.drawPixel(x + 8, y + 4, RGB(95, 55, 79));
    lcd.drawPixel(x + 9, y + 4, RGB(208, 230, 205));
    lcd.drawPixel(x + 10, y + 4, RGB(247, 253, 250));
    lcd.drawPixel(x + 11, y + 4, RGB(247, 253, 250));
    lcd.drawPixel(x + 12, y + 4, RGB(95, 55, 79));
    lcd.drawPixel(x + 13, y + 4, RGB(247, 253, 250));
    lcd.drawPixel(x + 14, y + 4, RGB(95, 55, 79));

    lcd.drawPixel(x + 1, y + 5, RGB(95, 55, 79));
    lcd.drawPixel(x + 2, y + 5, RGB(250, 185, 22));
    lcd.drawPixel(x + 3, y + 5, RGB(250, 185, 22));
    lcd.drawPixel(x + 4, y + 5, RGB(250, 185, 22));
    lcd.drawPixel(x + 5, y + 5, RGB(250, 185, 22));
    lcd.drawPixel(x + 6, y + 5, RGB(250, 185, 22));
    lcd.drawPixel(x + 7, y + 5, RGB(250, 185, 22));
    lcd.drawPixel(x + 8, y + 5, RGB(250, 185, 22));
    lcd.drawPixel(x + 9, y + 5, RGB(95, 55, 79));
    lcd.drawPixel(x + 10, y + 5, RGB(208, 230, 205));
    lcd.drawPixel(x + 11, y + 5, RGB(247, 253, 250));
    lcd.drawPixel(x + 12, y + 5, RGB(247, 253, 250));
    lcd.drawPixel(x + 13, y + 5, RGB(247, 253, 250));
    lcd.drawPixel(x + 14, y + 5, RGB(95, 55, 79));

    lcd.drawPixel(x + 1, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 2, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 3, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 4, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 5, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 6, y + 6, RGB(250, 185, 22));
    lcd.drawPixel(x + 7, y + 6, RGB(250, 185, 22));
    lcd.drawPixel(x + 8, y + 6, RGB(250, 185, 22));
    lcd.drawPixel(x + 9, y + 6, RGB(250, 185, 22));
    lcd.drawPixel(x + 10, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 11, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 12, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 13, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 14, y + 6, RGB(95, 55, 79));
    lcd.drawPixel(x + 15, y + 6, RGB(95, 55, 79));

    lcd.drawPixel(x, y + 7, RGB(95, 55, 79));
    lcd.drawPixel(x + 1, y + 7, RGB(253, 214, 133));
    lcd.drawPixel(x + 2, y + 7, RGB(247, 253, 250));
    lcd.drawPixel(x + 3, y + 7, RGB(247, 253, 250));
    lcd.drawPixel(x + 4, y + 7, RGB(247, 253, 250));
    lcd.drawPixel(x + 5, y + 7, RGB(253, 214, 133));
    lcd.drawPixel(x + 6, y + 7, RGB(95, 55, 79));
    lcd.drawPixel(x + 7, y + 7, RGB(250, 185, 22));
    lcd.drawPixel(x + 8, y + 7, RGB(250, 185, 22));
    lcd.drawPixel(x + 9, y + 7, RGB(95, 55, 79));
    lcd.drawPixel(x + 10, y + 7, RGB(247, 55, 10));
    lcd.drawPixel(x + 11, y + 7, RGB(247, 55, 10));
    lcd.drawPixel(x + 12, y + 7, RGB(247, 55, 10));
    lcd.drawPixel(x + 13, y + 7, RGB(247, 55, 10));
    lcd.drawPixel(x + 14, y + 7, RGB(247, 55, 10));
    lcd.drawPixel(x + 15, y + 7, RGB(247, 55, 10));
    lcd.drawPixel(x + 16, y + 7, RGB(95, 55, 79));

    lcd.drawPixel(x, y + 8, RGB(95, 55, 79));
    lcd.drawPixel(x + 1, y + 8, RGB(247, 253, 250));
    lcd.drawPixel(x + 2, y + 8, RGB(247, 253, 250));
    lcd.drawPixel(x + 3, y + 8, RGB(247, 253, 250));
    lcd.drawPixel(x + 4, y + 8, RGB(247, 253, 250));
    lcd.drawPixel(x + 5, y + 8, RGB(95, 55, 79));
    lcd.drawPixel(x + 6, y + 8, RGB(251, 132, 36));
    lcd.drawPixel(x + 7, y + 8, RGB(251, 132, 36));
    lcd.drawPixel(x + 8, y + 8, RGB(95, 55, 79));
    lcd.drawPixel(x + 9, y + 8, RGB(247, 55, 10));
    lcd.drawPixel(x + 10, y + 8, RGB(95, 55, 79));
    lcd.drawPixel(x + 11, y + 8, RGB(95, 55, 79));
    lcd.drawPixel(x + 12, y + 8, RGB(95, 55, 79));
    lcd.drawPixel(x + 13, y + 8, RGB(95, 55, 79));
    lcd.drawPixel(x + 14, y + 8, RGB(95, 55, 79));
    lcd.drawPixel(x + 15, y + 8, RGB(95, 55, 79));

    lcd.drawPixel(x, y + 9, RGB(95, 55, 79));
    lcd.drawPixel(x + 1, y + 9, RGB(247, 253, 250));
    lcd.drawPixel(x + 2, y + 9, RGB(247, 253, 250));
    lcd.drawPixel(x + 3, y + 9, RGB(253, 214, 133));
    lcd.drawPixel(x + 4, y + 9, RGB(95, 55, 79));
    lcd.drawPixel(x + 5, y + 9, RGB(251, 132, 36));
    lcd.drawPixel(x + 6, y + 9, RGB(251, 132, 36));
    lcd.drawPixel(x + 7, y + 9, RGB(251, 132, 36));
    lcd.drawPixel(x + 8, y + 9, RGB(251, 132, 36));
    lcd.drawPixel(x + 9, y + 9, RGB(95, 55, 79));
    lcd.drawPixel(x + 10, y + 9, RGB(247, 55, 10));
    lcd.drawPixel(x + 11, y + 9, RGB(247, 55, 10));
    lcd.drawPixel(x + 12, y + 9, RGB(247, 55, 10));
    lcd.drawPixel(x + 13, y + 9, RGB(247, 55, 10));
    lcd.drawPixel(x + 14, y + 9, RGB(247, 55, 10));
    lcd.drawPixel(x + 15, y + 9, RGB(95, 55, 79));

    lcd.drawPixel(x + 1, y + 10, RGB(95, 55, 79));
    lcd.drawPixel(x + 2, y + 10, RGB(95, 55, 79));
    lcd.drawPixel(x + 3, y + 10, RGB(95, 55, 79));
    lcd.drawPixel(x + 4, y + 10, RGB(95, 55, 79));
    lcd.drawPixel(x + 5, y + 10, RGB(251, 132, 36));
    lcd.drawPixel(x + 6, y + 10, RGB(251, 132, 36));
    lcd.drawPixel(x + 7, y + 10, RGB(251, 132, 36));
    lcd.drawPixel(x + 8, y + 10, RGB(251, 132, 36));
    lcd.drawPixel(x + 9, y + 10, RGB(251, 132, 36));
    lcd.drawPixel(x + 10, y + 10, RGB(95, 55, 79));
    lcd.drawPixel(x + 11, y + 10, RGB(95, 55, 79));
    lcd.drawPixel(x + 12, y + 10, RGB(95, 55, 79));
    lcd.drawPixel(x + 13, y + 10, RGB(95, 55, 79));
    lcd.drawPixel(x + 14, y + 10, RGB(95, 55, 79));

    lcd.drawPixel(x + 5, y + 11, RGB(95, 55, 79));
    lcd.drawPixel(x + 6, y + 11, RGB(95, 55, 79));
    lcd.drawPixel(x + 7, y + 11, RGB(95, 55, 79));
    lcd.drawPixel(x + 8, y + 11, RGB(95, 55, 79));
    lcd.drawPixel(x + 9, y + 11, RGB(95, 55, 79));
  }

  void drawPilars(Pilars& pilar)
  {
    if (pilar.x)
    {
      lcd.fillRect(pilar.x, 0, 30, pilar.top, GREEN);
      lcd.fillRect(pilar.x, pilar.top + 30, 30, pilar.bottom, GREEN);
  
      lcd.drawVerticalLine(pilar.x + 30, 0, pilar.top, RGB(113, 197, 207));
      lcd.drawVerticalLine(pilar.x + 30, pilar.top + 30, pilar.bottom, RGB(113, 197, 207));
    }
    else
    {
      lcd.fillRect(pilar.x, 0, 31, pilar.top, RGB(113, 197, 207));
      lcd.fillRect(pilar.x, pilar.top + 30, 31, pilar.bottom, RGB(113, 197, 207));

      Pilar1.x = lcd.width - 30;
      Pilar1.top = random(30, lcd.height - Floor.height - 30);
      Pilar1.bottom = lcd.height - Floor.height - Pilar1.top - 30;
      Pilar1.isPassed = false;
    }
  }

  void showScore()
  {
    lcd.drawString(Score.x, Score.y, "Score : ", Score.color, Score.fontsize);

    word score[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for (unsigned i = power(10, countDigits(Score.value[1])), k = 0; i > 1 ; k += 6)
    {
      Serial.println(i);
      lcd.drawString(Score.x + 50 + k, Score.y, score[Score.value[0] % i / (i /= 10)], Score.color, Score.fontsize);
    }
    if (!Score.value[0])
    {
      lcd.drawString(Score.x + 50, Score.y, score[0], Score.color, Score.fontsize);
    }

  }

  unsigned power(byte num1, byte num2)
  {
    for(byte i = num2 - 1; i > 0 ; i--)
    {
      num1 *= num1;
    }
    return num1;
  }

  byte countDigits(unsigned num)
  {
    byte count = 0;
    while (num) {
      num = num / 10;
      count++;
    }
    return count;
  }

  word RGB( byte R, byte G, byte B)
  {
    return ( ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3) );
  }
} Game;

void setup() {
  Serial.begin(9600);

  randomSeed(analogRead(A5));

  lcd.init(lcd.VERTICAL);

  Game.Init();
}

void loop() {
  Game.Run();
}
