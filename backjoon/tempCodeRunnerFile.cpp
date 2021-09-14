r = N - q;

        // 반복되는 문자열이 없는 경우
        if (q == 0 || q % r != 0)
            puts("1");
        // 반복되는 문자열이 있는 경우
        else
            printf("%d\n %d %d