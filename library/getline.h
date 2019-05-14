//
// Created by liu on 18-11-24.
//

#ifndef CHESS_GETLINE_H
#define CHESS_GETLINE_H

#endif //CHESS_GETLINE_H
/**
 * get a line from the terminal,
    once one line is finished, exit the function
 * @param s a string(to contain the input, large enough),
 * @param lim an int to limit the input size
 * @return the length of the input
 */
int mygetline(char s[], int lim) {

    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
