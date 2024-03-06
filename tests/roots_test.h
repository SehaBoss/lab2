#ifndef ROOTS_TEST_H
#define ROOTS_TEST_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "roots.h"
}

TEST(RootsTest, num) {
    ASSERT_STREQ(roots(-1,2,3), "-1.00;3.00");
    ASSERT_STRCASEEQ(roots(2,2,3), "Нет корней");
    ASSERT_STREQ(roots(2,4,2), "-1.00");
}

TEST(RootsTest, inputFile) {
    char *filename = (char *)malloc(sizeof(char) * 1024);
    sprintf(filename, "%s/inputr.txt", INPUTDIR);

    int fd = open(filename, O_RDONLY);
    free(filename);
    if (fd < 0) {
        ASSERT_EQ(errno, 0);
    }

    char *buf = (char *)malloc(sizeof(char) * 512);
    int readcount = read(fd, buf, 512);
    ASSERT_TRUE(readcount > 0);
    close(fd);

    int a = 0;
    int b =0;
    int c = 0;
    char output[20];
    int ret = sscanf(buf, "%d %d %d %s", &a, &b, &c, &output);
    free(buf);
    ASSERT_EQ(ret, 4);

    char* result = roots(a,b,c);
    ASSERT_STRCASEEQ(result, output);
}

#endif // ROOTS_TEST_H
