# Find
**Category:** Misc
**Points:** 1000
**Description:**
[you_can_find.txt](you_can_find.txt)

```
# content of file: you_can_find.txt
INXW4sZ3SMFdsg2HUIBkjOlFYFvAUnQnrJANByQWG23FOoIQGIp3u3FOMQGqM33SEBWcG65TFEnB3WQYLfUEBXrXI2DFtOJZS
A53POVdWGddIdIfbDmON52,CAZDndPEbBvTG64pRAiNVuXW4ewZLZqFYeQAUgCT/IPJ.5TAY'ZUMRS;TGZJoTMYZDIuZDGolGFlRGGmNRX
MM4DCZgjJklXG;;EYDAsOJRerHBfSWIdhM3h5BI======
```

**Hint 1**: Хэрэгцээт тэмдэгтүүдийг цуглуул.
**Hint 2**: regex+decode

## Write-up
Base32-д ордог тэмдэгтүүдийг түүж аваад decode хийнэ. Доор нийтлэгдсэн кодыг харна уу.

Тэмцээн дээр hint нийтлэгдсэний дараа л бодлогын санаа орж ирсэн. base32-н талаар арай дэлгэрэнгүй ойлголттой байсан бол файлын төгсгөлд байх `======`-г хараад таамаглаж болох байсан байна лээ.

```python
# source on python 2.7
import base64

data = open("you_can_find.txt").read()
characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567="

result = ""
for c in data:
    if c in characters:
        result += c

print base64.b32decode(result)
```

Хариу: `hz{0c4de3e3f24df1bc67c81e7100918ed3}`
