# xtranslator

A simple c++ program that takes a value from an X selection like PRIMARY, SECONDARY or CLIPBOARD and then translates it using the lingva api. Progream is to be used with linux pipes and shortcuts, not directly.
> **Warning**
> Program works only on linux with X server!!!!

## Installation and build
### Install dependencies
#### Arch-based distro
```
sudo pacman -S curl nlohmann-json
```
#### Debian-based distro
```
sudo apt install libcurl-dev nlohmann-json-dev
```

### Clone with submodules
```
git clone https://github.com/aqbifzl/xtranslator.git --recursive && cd xtranslator
```
```
sudo make build install clean
```
## Basic usage
```xtranslator [text_source] [source_language] [target_language]```
> I recommend using PRIMARY or CLIPBOARD for text_source. PRIMARY means this clipboard working with text selection and pasting with scroll, CLIPBOARD is just a "standard" CLIPBOARD.
> For source_language and target_language i recommend using symbols from list below, it's an example list i got from listLanguages function from lingva api, should works also for other instances.
## Examples of use
```
xtranslator PRIMARY auto pl | xargs -I {} xdotool type "{}"
```
> This one will take the selected text, e.g. in the native language, and translate it into the desired target language, and then type it in selected place, useful with communicators.
```
xtranslator PRIMARY auto pl | xargs -I {} notify-send "{}"
```
> It will do the same thing just send the result as a notification, useful for translating someone else's text into your native language

> **Note**
> I recommend setting these commands as a shortcut.

## Example list of language codes
```
Detect - auto
Afrikaans - af
Albanian - sq
Amharic - am
Arabic - ar
Armenian - hy
Assamese - as
Aymara - ay
Azerbaijani - az
Bambara - bm
Basque - eu
Belarusian - be
Bengali - bn
Bhojpuri - bho
Bosnian - bs
Bulgarian - bg
Catalan - ca
Cebuano - ceb
Chichewa - ny
Chinese - zh
Chinese (Traditional) - zh_HANT
Corsican - co
Croatian - hr
Czech - cs
Danish - da
Dhivehi - dv
Dogri - doi
Dutch - nl
English - en
Esperanto - eo
Estonian - et
Ewe - ee
Filipino - tl
Finnish - fi
French - fr
Frisian - fy
Galician - gl
Georgian - ka
German - de
Greek - el
Guarani - gn
Gujarati - gu
Haitian Creole - ht
Hausa - ha
Hawaiian - haw
Hebrew - iw
Hindi - hi
Hmong - hmn
Hungarian - hu
Icelandic - is
Igbo - ig
Ilocano - ilo
Indonesian - id
Irish - ga
Italian - it
Japanese - ja
Javanese - jw
Kannada - kn
Kazakh - kk
Khmer - km
Kinyarwanda - rw
Konkani - gom
Korean - ko
Krio - kri
Kurdish (Kurmanji) - ku
Kurdish (Sorani) - ckb
Kyrgyz - ky
Lao - lo
Latin - la
Latvian - lv
Lingala - ln
Lithuanian - lt
Luganda - lg
Luxembourgish - lb
Macedonian - mk
Maithili - mai
Malagasy - mg
Malay - ms
Malayalam - ml
Maltese - mt
Maori - mi
Marathi - mr
Meiteilon (Manipuri) - mni-Mtei
Mizo - lus
Mongolian - mn
Myanmar (Burmese) - my
Nepali - ne
Norwegian - no
Odia (Oriya) - or
Oromo - om
Pashto - ps
Persian - fa
Polish - pl
Portuguese - pt
Punjabi - pa
Quechua - qu
Romanian - ro
Russian - ru
Samoan - sm
Sanskrit - sa
Scots Gaelic - gd
Sepedi - nso
Serbian - sr
Sesotho - st
Shona - sn
Sindhi - sd
Sinhala - si
Slovak - sk
Slovenian - sl
Somali - so
Spanish - es
Sundanese - su
Swahili - sw
Swedish - sv
Tajik - tg
Tamil - ta
Tatar - tt
Telugu - te
Thai - th
Tigrinya - ti
Tsonga - ts
Turkish - tr
Turkmen - tk
Twi - ak
Ukrainian - uk
Urdu - ur
Uyghur - ug
Uzbek - uz
Vietnamese - vi
Welsh - cy
Xhosa - xh
Yiddish - yi
Yoruba - yo
Zulu - zu
```