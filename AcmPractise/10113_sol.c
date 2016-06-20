#include<stdio.h>
 

#define SIZE_NAME 21
#define SIZE_ITEM 61
 

char Name[SIZE_ITEM][SIZE_NAME];
int NameLen;
 

int nameComp(char st1[], char st2[])
{
      int i;
      for (i=0; st1[i] && st2[i] && st1[i]==st2[i]; i++);
      if (st1[i] == st2[i])
            return 1;
      return 0;
}
 

int searchName(char st[])
{
      int i;
      for (i=0; i<NameLen; i++) if (nameComp(st, Name[i]))
            return i;
      return -1;
}
 

int mcd(int a, int b)
{
      if (a%b == 0) 
            return b;
      return mcd(b, a%b);
}
 

int m, n;
char sign;
char s1[SIZE_NAME], s2[SIZE_NAME];
int x, y;
int Ratio[SIZE_ITEM][SIZE_ITEM];
 

void nameCopy(char dest[], char src[])
{
      int i;
      for (i=0; src[i]; i++)
            dest[i] = src[i];
      dest[i] = src[i];
}
 

void readAssertion()
{
      scanf("%d %s %c %d %s ", &m, s1, &sign, &n, s2);
}
 

int used[SIZE_ITEM];
 

void resetUsed()
{
      int i;
      for (i=0; i<NameLen; i++)
            used[i] = 0;
}
 

void updateRatio(int i, int j)
{
      int k;
      int a, b, d;
      used[j] = 1;
      for (k=0; k<NameLen; k++) {
            if (!used[k] && !Ratio[i][k] && Ratio[j][k]) {
                  a = Ratio[i][j] * Ratio[j][k];
                  b = Ratio[j][i] * Ratio[k][j];
                  d = mcd(a, b);
                  a /= d;
                  b /= d;
                  Ratio[i][k] = a;
                  Ratio[k][i] = b;
                  updateRatio(i, k);
                  updateRatio(k, i);
            }
      }
}
 

void solveAssertion()
{
      int a, b, d;
      d = mcd(m,n);
      m /= d;
      n /= d;
      a = searchName(s1);
      if (-1 == a) {
            nameCopy(Name[NameLen], s1);
            a = NameLen++;
      }
      b = searchName(s2);
      if (-1 == b) {
            nameCopy(Name[NameLen], s2);
            b = NameLen++;
      }
      Ratio[a][b] = m;
      Ratio[b][a] = n;
}
 

void readQuery()
{
      scanf("%s %c %s ", s1, &sign, s2);
}
 

void printQuery()
{
    int a, b, i;
      a = searchName(s1);
      b = searchName(s2);
      resetUsed();
      used[a] = 1;
      for (i=0; i<NameLen; i++) if (!used[i] && Ratio[a][i])
            updateRatio(a, i);
      if (Ratio[a][b])
            printf("%d %s = %d %s\n", Ratio[a][b], s1, Ratio[b][a], s2);
      else
            printf("? %s = ? %s\n", s1, s2);
}
 

int main()
{
      NameLen = 0;
      while (1 == scanf("%c", &sign)) {
            if (sign == '.') 
                  break;
            else if (sign == '!') {
                  readAssertion();
                  solveAssertion();
            }
            else {
                  readQuery();
                  printQuery();
            }
      }
      return 0;
}