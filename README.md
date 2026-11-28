echo "# myLab" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/hkmtakgn/myLab.git
git push -u origin main
…or push an existing repository from the command line
git remote add origin https://github.com/hkmtakgn/myLab.git
git branch -M main
git push -u origin main
-------------------------------------------------------------
# cc -Wall -Wextra -Werror -c ft_isalpha.c

Bu komutun parçaları:

# cc: C derleyicisi (C Compiler).

# -Wall -Wextra -Werror: uyarıları açan bayraklar. Subject bunları zorunlu tutuyor. Şimdilik "kodda en ufak sorun varsa derleme durur" diye bilmen yeterli.

# -c: "sadece derle" demek. Sonuçta çalıştırılabilir program değil, ft_isalpha.o dosyası çıkar. .o (object) dosyası makine diline çevrilmiş ama henüz tek başına çalışamayan bir parça.

# Makefile kurallardan oluşur. Her kuralın üç parçası vardır: 

make
hedef: bağımlılık
	komut


# hedef: üretmek istediğin dosya.
# bağımlılık: o dosyayı üretmek için gereken dosya.
# komut: hedefi üretmek için çalıştırılacak komut.

# Okunuşu şöyle: "hedef, bağımlılık'tan üretilir; bunun için komut'u çalıştır."

⚠️ Komut satırının başındaki boşluk TAB karakteri olmalı. 4 boşluk yazarsan çalışmaz.
-------------------------------------------------------------
ft_isalpha.o: ft_isalpha.c
	cc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o

# Burada yeni bir bayrak var: -o (output), çıktı dosyasının adını belirler. Daha önce kullanmadık çünkü -c adı zaten otomatik veriyordu. Makefile'da ise genelde açıkça yazılır.
-------------------------------------------------------------
cc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o

# -c: "sadece derle, link etme"
# -o ft_isalpha.o: "çıktının adı ft_isalpha.o olsun"
-------------------------------------------------------------
ft_isalpha.o dosyası hiç yoksa ?

# Hedef yoksa make onu üretir.
# Bağımlılık hedeften daha yeniyse make hedefi yeniden üretir.
# Hedef bağımlılıktan daha yeniyse hiçbir şey yapmaz (is up to date).
-------------------------------------------------------------
# Çok sayıda kural varsa eğer;

# make çalışınca ilk kuralı çalıştırır.

yani ; 

ft_isalpha.o: ft_isalpha.c
	cc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o

ft_isdigit.o: ft_isdigit.c
	???

# ft_isalpha.o olan hedef dosya ft_isalpha.c olan bağımlılık dosyasından yeni ise 'up to date' mesajı "dosya güncel" demek
# Değilse yeniden üretim için bağımlılık ft_isalpha.c dosyasını altında 'TAB' kadar boşluk ile girintiyle başlayan komut ile derler ve yeniden ft_alpha.o derlenmiş çalıştırılmaya hazır dosyayı oluşturur.
-------------------------------------------------------------
herşey: ____________  ____________

ft_isdigit.o: ft_isdigit.c
	cc -Wall -Wextra -Werror -c ft_isdigit.c -o ft_isdigit.o

ft_isalpha.o: ft_isalpha.c
	cc -Wall -Wextra -Werror -c ft_isalpha.c -o ft_isalpha.o

# En üste herşey adında yeni bir kural koydum.
# Bu kuralın altında komut satırı olmadığını da fark etmişsindir. Bu şimdilik doğru, çünkü bu kuralın tek işi diğer kuralları tetiklemek.

make
 └─ herşey (ilk kural) → ft_isdigit.o ve ft_isalpha.o gerekli
      ├─ ft_isdigit.o yok → kendi kuralını çalıştır → ft_isdigit.c'yi derle
      └─ ft_isalpha.o yok → kendi kuralını çalıştır → ft_isalpha.c'yi derle

# İsim: herşey → all

# Make'te bu kural için herkesin kullandığı bir isim var: all (İngilizce "hepsi"). Subject de Makefile'da all kuralının olmasını zorunlu tutuyor ve moulinette bu ismi arıyor. Ayrıca kural adlarında ş gibi Türkçe karakterlerden kaçınmak gerekiyor.

# Yapman gerekenler
# herşey yazan yeri all yap.
-------------------------------------------------------------
# Sadece make yazınca ilk kural çalışır.

# make hedef yazınca adını verdiğin kural çalışır.

# all kuralı bağımlılıkları üzerinden diğer kuralları zincir halinde tetikler.

# Make sadece eskimiş hedefleri yeniden üretir.
-------------------------------------------------------------
# Değişken, bir metne isim vermek demek. Makefile'da iki adımda çalışır:

ISIM = değer        # tanımlama
$(ISIM)             # kullanma: make bunu "değer" ile değiştirir

Make, $(ISIM) gördüğü her yere değer yazar. Yani sadece metin değiştirir.

# Makefile'ın en üstüne, all kuralından önce bu iki değişkeni tanımla.

# Kurallardaki cc -Wall -Wextra -Werror yazan yerleri değişkenlerle değiştir.
-------------------------------------------------------------


CC = cc
CFLAGS = -Wall -Wextra -Werror

all:ft_isdigit.o ft_isalpha.o

ft_isdigit.o:ft_isdigit.c
	$(CC) $(CFLAGS) -c ft_isdigit.c -o ft_isdigit.o

ft_isalpha.o:ft_isalpha.c
	$(CC) $(CFLAGS) -c ft_isalpha.c -o ft_isalpha.o


-------------------------------------------------------------
