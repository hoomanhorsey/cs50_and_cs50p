
 // return toupper(word[0]) - 'A'; // original hash function.

char *hash[2];

if (((word[0] - 'A') > 0) && ((word[0] - 'A') < 10))
{
    hash[0] = 0;
    hash[1] = (word[0] - 'A');
}

if (((word[0] - 'A') > 9) && ((word[0] - 'A') < 20))
{
    hash[0] = 0;
    hash[1] = (word[0] - 55);
}

if (((word[0] - 'A') > 19) && ((word[0] - 'A') < 26))
{
    hash[0] = 2;
    hash[1] = (word[0] - 45);
}


if (word[1] - 'A' == NULL)
{
    hash[2] = 0;
}

if (((word[0] - 'A') > 0) && ((word[0] - 'A') < 4))
{
    hash[2] = 0;
}

if (((word[0] - 'A') > 3) && ((word[0] - 'A') < 8))
{
    hash[2] = 1;
}

if (((word[0] - 'A') > 7) && ((word[0] - 'A') < 14))
{
    hash[2] = 2;
}

if (((word[0] - 'A') > 13) && ((word[0] - 'A') < 20))
{
    hash[2] = 3;
}

if (((word[0] - 'A') > 19) && ((word[0] - 'A') < 26))
{
    hash[2] = 4;
}

return hash;




 // return toupper(word[0]) - 'A'; // original hash function.


hashvalue = (toupper(word[0]) - 'A') + (toupper(word[1]) - 'A');


return hashvalue;





// slow
int hashvalue = 0;
int i = 0;

for (i = 0; i < 6; i++)
// for (i = 0; i < 2 || isalpha(word[i]); i++)

// while (isalpha(word[i]))
{
    if (isalpha(word[i] == 0))
    {
       break;
    }
    hashvalue += ((toupper(word[i]) - 'A') + 10000);







Fastest function so far

int hashvalue = 0;
int i = 0;
while (isalpha(word[i]))

//while (word[i] != 0)
{
    hashvalue += ((toupper(word[i]) - 'A') + 10000);
    i++;
}


