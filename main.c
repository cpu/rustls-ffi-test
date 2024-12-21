#include <stdio.h>
#include <rustls.h>

int main(void)
{
    const rustls_str version = rustls_version();
    printf("%.*s\n", (int)version.len, version.data);
    return 0;
}
