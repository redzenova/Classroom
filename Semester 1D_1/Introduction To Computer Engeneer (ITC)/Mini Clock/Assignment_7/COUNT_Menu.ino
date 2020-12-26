void COUNT_Menu() {
  if (Lock_menu_btn != true) {
    if (digitalRead(btn[1]) == LOW) {
      beep();
      delay(120);
      clear_display();
      st_state[7] = true;
      Lock_menu_btn = true;
    }
  }

  if (st_state[7] == true) {
    if (CountStart != true) {
      if (digitalRead(btn[3]) == LOW) {
        beep();
        delay(120);
        if (COUNT_MENU > 4) COUNT_MENU = 0;
        COUNT_MENU ++;
        clear_display();
      }
    }

    if (COUNT_MENU == 1) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        c_hour++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        c_hour--;
      }
      if ( c_hour > 59 ) c_hour = 0;
      if ( c_hour <  0 ) c_hour = 59;

      clear_display();
      delay(1);
      print_tiny_char( 2, 1,  c_hour / 10 + '0'); //print hour
      print_tiny_char( 6, 1,  c_hour % 10 + '0');
    }

    if (COUNT_MENU == 2) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        c_minute++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        c_minute--;
      }
      if ( c_minute > 59 ) c_minute = 0;
      if ( c_minute <  0 ) c_minute = 59;

      clear_display();
      delay(1);
      print_tiny_char(12, 1, c_minute / 10 + '0'); //print minute
      print_tiny_char(16, 1, c_minute % 10 + '0');
    }

    if (COUNT_MENU == 3) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        c_second_set++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        c_second_set--;
      }
      if ( c_second_set > 59 ) c_second_set = 0;
      if ( c_second_set <  0 ) c_second_set = 59;

      clear_display();
      delay(1);
      print_tiny_char(22, 1, c_second_set / 10 + '0'); //print second
      print_tiny_char(26, 1, c_second_set % 10 + '0');
    }

    if (COUNT_MENU == 4) {
      if (CountStart != true) {
        if (digitalRead(btn[1]) == LOW) {
          beep();
          CountStart = true;
          c_millis_msec = millis();
          clear_display();
          swap = c_second_set ;
        }
      }

      if (digitalRead(btn[0]) == LOW) {
        beep();
      
      }
    }

    if (COUNT_MENU == 5) {
      if (digitalRead(btn[1]) == LOW) {
        beep();
        clear_display();
        st_state[7] = false;
        Lock_menu_btn = false;
      }

    }

  }
}
