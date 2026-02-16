# libsha1-go
Last version: 0.0.1

Pure sha1 function use nothing else. Exported from golang runtime. And some examples of code.

## Requirements
To compile library and examples you will need to install
- c99 capable compiler (for now only gcc >=4.8 supported)
- openssl >=1.0 ( libcrypto )
- golang >=1.6

## Prepare system
Instructions for Debian/Ubuntu like systems:
```
apt install build-essential
apt install libssl-dev
apt install golang-go
```

## Compile

If your version of go not default:
```
GOROOT=/path/to/golang/installdir GO=go-x.y make lib
```

## Reason
Not found library with only one function, so I tryed by myself.

## Result
Slightly faster file reading than `sha1sum` command.
But more memory consuming.

## API
- **libsha1_go__version**(void): Returns doted version string.

  return: `* char`

  *since*: 0.0.1

- **libsha1_go__version_go**(void): Returns version string of go rutime used.

  return: `* char`

  *since*: 0.0.1

- **libsha1_go__SHA1_hexdigest**(char* text): Return hexed-string with sha1 digest.

  params:
  - text (`char *`): input string

  return: `char *` String with hexed digest

  *since*: 0.0.1

- **libsha1_go__SHA1File_hexdigest**(char* fullPath): Return hexed-string with sha1 digest of contents of the file.

  params:
  - fullPath (`char *`): input full path to file as string

  return: `char *` String with hexed digest, if error occured - empty string returns

  *since*: 0.0.1

- **libsha1_go__SHA1_digest**(char* text): Return non hexed(byte)-string with sha1 digest.

  params:
  - text (`char *`): input string

  return: `char *` Bytes array, char string with digest

  *since*: 0.0.1

- **libsha1_go__FreeResult**(char* ptr): frees memory allocated for sha1 degest earlier.

  return: `void`

  *since*: 0.0.1
