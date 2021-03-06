#include <stdio.h>
#include <string.h>
typedef unsigned int uint;
static uint seed;
static uint mrand(uint num)
{
    seed = seed * 1103515245 + 37209;
    return ((seed >> 8) % num);
}

int get_next_int()
{
    int i;
    scanf("%i", &i);
    return i;
}

#define MIN_LEN 8
#define MAX_LEN 50
#define MAX_EMAILS 4000

static char pool[MAX_EMAILS][MAX_LEN];
static char* base[MAX_EMAILS];
static int len[MAX_EMAILS];
static int n;
static char prefix[MAX_LEN];
static const char alpha[] = "0123456789abcdefghijklmnopqrstuvwxyz";
static const int alphalen = sizeof(alpha) - 1;
static int max_len;

void gen_email(char *word, int &len)
{
    len = MIN_LEN + mrand(max_len - MIN_LEN);
    int at = 1 + mrand(len - 2);

    for (int i = 0; i < len; ++i)
    {
        word[i] = alpha[mrand(alphalen)];
    }
    word[at] = '@';
    word[len] = 0;
}

void gen_email_from_exist(char *word, int &wlen, char *src, int slen)
{
    wlen = MIN_LEN + mrand(max_len - MIN_LEN);
    int prefix_len = 1 + mrand(wlen - MIN_LEN/2);
    if (prefix_len > slen) prefix_len = slen;

    int i = 0;
    bool at_exist = false;

    // copy part of src
    for (i = 0; i < prefix_len; ++i)
        if ((word[i] = src[i]) == '@') at_exist = true;

    // remain
    for (; i < wlen; ++i)
        word[i] = alpha[mrand(alphalen)];

    if (!at_exist)
    {
        int at = prefix_len + 1 + mrand(wlen - prefix_len - 2);
        word[at] = '@';
    }

    word[wlen] = 0;
}

// user API
void init();
void add(const char *email);
void del(const char *email);
int find(const char *prefix);

int test_random()
{
    scanf("%u", &seed);
    max_len = get_next_int();
    int ncmd = get_next_int();

    if (base[0] == nullptr)
        for (int i = 0; i < MAX_EMAILS; ++i) base[i] = pool[i];

    int x, s = 0;
    n = 0;

    init();

    enum {
        cmd_del = 0,
        cmd_add = 2,
        cmd_find = 6,
        cmd_n
    };

    for (int i = 0; i < ncmd; ++i)
    {
        int cmd = mrand(cmd_n);

        if (n == 0) cmd = cmd_add;

        if (cmd <= cmd_del) // del
        {
            x = mrand(n);
            del(base[x]);
            --n;

            // move last email to [x]
            if (x < n)
            {
                char *tmp = base[x];
                base[x] = base[n];
                base[n] = tmp;
            }
        }
        else if (cmd <= cmd_add && n < MAX_EMAILS) // add
        {
            char *p = base[n];

            int method = mrand(2);

            if (method > 0 && n > 0)
            {
                x = mrand(n);
                gen_email_from_exist(p, len[n], base[x], len[x]);
            }
            else
                gen_email(p, len[n]);

            add(p);
            ++n;
        }
        else if (cmd <= cmd_find) // find
        {
            x = mrand(n);
            int prefix_len = 1 + mrand(len[x] - 1);
            for (int i = 0; i < prefix_len; ++i)
                prefix[i] = base[x][i];
            prefix[prefix_len] = 0;
            int res = find(prefix);
            s += res;
        }
        else
            --i; // try again
    }

    int correct = get_next_int();
    return s == correct;
}

bool test_manual()
{
    char cmd[16];
    bool ok = true;

    init();

    while (true)
    {
        scanf("%s", cmd);
        if (!strcmp(cmd, "add"))
        {
            scanf("%s", prefix);
            add(prefix);
        }
        else if (!strcmp(cmd, "del"))
        {
            scanf("%s", prefix);
            del(prefix);
        }
        else if (!strcmp(cmd, "find"))
        {
            scanf("%s", prefix);
            int res = find(prefix);
            int correct = get_next_int();
            if (res != correct) ok = false;
        }
        else
            break;
    }
    return ok;
}

bool test()
{
    char method[16];
    scanf("%s", method);
    if (!strcmp(method, "[RND]"))
        return test_random();
    else if (!strcmp(method, "[MAN]"))
        return test_manual();
    printf("Error %s\n", method);
    return false;
}
#include<iostream>
int main()
{
	std::cout << "safsdfsda" << std::endl;
    setbuf(stdout, NULL);
    freopen("../../repos/tests/Tests/ListList/input_acad_easy.txt", "r", stdin);
    int ntests = 0;
    scanf("%i", &ntests);
    for (int t = 1; t <= ntests; ++t)
    {
        printf("#%i %i\n", t, test() ? 100 : 0);
    }
    return 0;
}
