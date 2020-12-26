void ALARM_Menu() {
  if (digitalRead(btn[1]) == LOW) {
    beep();
    delay(120);
    clear_display();
    st_state[8] = true;
    Lock_menu_btn = true;
  }

  if (st_state[8] == true) {
    if (AlarmStart != true) {
      if (digitalRead(btn[3]) == LOW) {
        beep();
        delay(120);
        if (ALARM_MENU > 4) ALARM_MENU = 0;
        ALARM_MENU ++;
        clear_display();
      }
    }

    if (ALARM_MENU == 1) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        delay(120);
        a_hour++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        delay(120);
        a_hour--;
      }
      if ( a_hour > 23 ) a_hour = 0;
      if ( a_hour <  0 ) a_hour = 23;

      delay(1);
      print_tiny_char( 2, 1,  a_hour / 10 + '0'); //print hour
      print_tiny_char( 6, 1,  a_hour % 10 + '0');
      print_tiny_char(12, 1, a_minute / 10 + '0'); //print minute
      print_tiny_char(16, 1, a_minute % 10 + '0');
      print_tiny_char(22, 1, a_second_set / 10 + '0'); //print second
      print_tiny_char(26, 1, a_second_set % 10 + '0');
    }

    if (ALARM_MENU == 2) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        delay(120);
        a_minute++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        delay(120);
        a_minute--;
      }
      if ( a_minute > 59 ) a_minute = 0;
      if ( a_minute <  0 ) a_minute = 59;

      delay(1);
      print_tiny_char( 2, 1,  a_hour / 10 + '0'); //print hour
      print_tiny_char( 6, 1,  a_hour % 10 + '0');
      print_tiny_char(12, 1, a_minute / 10 + '0'); //print minute
      print_tiny_char(16, 1, a_minute % 10 + '0');
      print_tiny_char(22, 1, a_second_set / 10 + '0'); //print second
      print_tiny_char(26, 1, a_second_set % 10 + '0');
    }

    if (ALARM_MENU == 3) {
      if (digitalRead(btn[2]) == LOW) {
        beep();
        delay(120);
        a_second_set++;
      }
      if (digitalRead(btn[0]) == LOW) {
        beep();
        delay(120);
        a_second_set--;
      }
      if ( a_second_set > 59 ) a_second_set = 0;
      if ( a_second_set <  0 ) a_second_set = 59;

      delay(1);
      print_tiny_char( 2, 1,  a_hour / 10 + '0'); //print hour
      print_tiny_char( 6, 1,  a_hour % 10 + '0');
      print_tiny_char(12, 1, a_minute / 10 + '0'); //print minute
      print_tiny_char(16, 1, a_minute % 10 + '0');
      print_tiny_char(22, 1, a_second_set / 10 + '0'); //print second
      print_tiny_char(26, 1, a_second_set % 10 + '0');
    }

    if (ALARM_MENU == 4) {
      if (digitalRead(btn[1]) == LOW) {
        ALARM_MENU++;
      }

      if (digitalRead(btn[2]) == LOW) {
        clear_display();
        beep();
        delay(120);
        no_alarm = false;
      }

      if (digitalRead(btn[0]) == LOW) {
        clear_display();
        beep();
        delay(120);
        no_alarm = true;
      }
    }
