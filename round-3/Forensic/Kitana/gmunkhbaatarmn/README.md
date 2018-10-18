# Haruulzangi 2018 Round 3 : Kitana

**Category:** Forensic
**Points:** 856
**Solves:** 5
**Description:**

>You will learn respect!
>--Kitana
> link [kitana.pcapng](kitana.pcapng)
## Write-up
Packet-г `tcpflow` ашиглан уншия:
```sh
tcpflow -r kitana.pcapng
```

`004.005.006.007.12345-008.009.010.011.02355` гэсэн нэртэй ганцхан файл үүснэ. Энэ файлыг нээж үзвэл JPEG зураг байсан ба зурган дээр flag маань дүрслэгдсэн байв:

![004.005.006.007.12345-008.009.010.011.02355](004.005.006.007.12345-008.009.010.011.02355?raw=true)

Flag: `HZ{KiTaNA_is_BeAsT_!!!}`
