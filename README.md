# Hunter Game

## Giới thiệu
- Họ và tên: Đỗ Thị Bích Ngọc
- Mã sinh viên: 23020689
- Lớp: K68-J

## Giới thiệu game
### Câu chuyện
- Nhân vật chính là chú ếch tên Hunter. Hunter tham gia một cuộc thi chạy marathon, trên đường chạy, Hunter gặp rất nhiều chướng ngại vật và phải vượt qua chúng để có thể tiếp tục với hành trình chạy marathon của mình.
### Mục lục
- [1. Cách tải game](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#1-c%C3%A1ch-t%E1%BA%A3i-game)
  + [a) Không bao gồm code](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#a-kh%C3%B4ng-bao-g%E1%BB%93m-code)
  + [b) Bao gồm code và có thể biên dịch](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#b-bao-g%E1%BB%93m-code-v%C3%A0-c%C3%B3-th%E1%BB%83-bi%C3%AAn-d%E1%BB%8Bch)
       [Cài đặt thư viện SDL](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#c%C3%A0i-%C4%91%E1%BA%B7t-th%C6%B0-vi%E1%BB%87n-sdl)
       [Cài đặt và chạy game](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#c%C3%A0i-%C4%91%E1%BA%B7t-v%C3%A0-ch%E1%BA%A1y-game)
- [2) Bắt đầu game](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#2-b%E1%BA%AFt-%C4%91%E1%BA%A7u-game)
- [3) Các thành phần trong game](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#3-c%C3%A1c-th%C3%A0nh-ph%E1%BA%A7n-trong-game)       
- [4) Cách chơi](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#4-c%C3%A1ch-ch%C6%A1i)
  + [a) Chức năng của các đối tượng trong game](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#a-ch%E1%BB%A9c-n%C4%83ng-c%E1%BB%A7a-c%C3%A1c-%C4%91%E1%BB%91i-t%C6%B0%E1%BB%A3ng-trong-game)
- [5) Kết thúc Game](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#5-k%E1%BA%BFt-th%C3%BAc-game)
- [6) Các tính năng của Hunter Game](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#6-c%C3%A1c-t%C3%ADnh-n%C4%83ng-c%E1%BB%A7a-hunter-game)
- [7) Hướng phát triển về sau](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#7-h%C6%B0%E1%BB%9Bng-ph%C3%A1t-tri%E1%BB%83n-v%E1%BB%81-sau)
- [Source Code Game](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#source-code-game)
- [Nguồn ảnh/icon](https://github.com/DoThiBichNgoc21/Hunter/new/master?filename=README.md#ngu%E1%BB%93n-%E1%BA%A3nhicon)     

## 1. Cách tải game
### a) Không bao gồm code
Nếu bạn chỉ muốn tải và chơi Game thì chỉ cần tải và giải nén file đã được đóng gói trong link dưới đây:

Sau khi giải nén thành công, click vào file Hunter_Game.exe là có thể bắt đầu chơi luôn.

### b) Bao gồm code và có thể biên dịch
Đầu tiên, hãy đảm bảo rằng máy tính của bạn đã cài đặt mingW thư viện SDL2 ( bao gồm cả SDL_image, SDL_mixer và SDL_ttf).

#### Cài đặt thư viện SDL
- Hướng dẫn cài SDL: https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php .

- Hướng dẫn cài SDL_image: https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php .

- Hướng dẫn cài SDL_mixer: https://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php .

- Hướng dẫn cài SDL_ttf: https://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php .

#### Cài đặt và chạy game
- Tải game dưới dạng file zip hoặc mở cmd và nhập lệnh sau:

- Mở project ( giải nén file nếu cần ), click vào file có đuôi .cbp để mở tất cả các code của game sau đó chạy chương trình và tiến hành chơi game.
- Nếu không thể chạy game, hãy liên hệ qua Email: dtbntq21@gmail.com .

## 2) Bắt đầu game
- Chờ một chút cho đến khi cửa sổ Menu của game hiện ra.


- Nếu bạn chưa muốn chơi game luôn thì click chuột vào nút Exit, cửa sổ sẽ lập tức đóng lại.
- Để biết được cách chơi, bạn Click chuột vào nút Help.
  + Sau khi đọc xong hướng dẫn, bạn Click vào nút để quay trở lại Menu.
- Click chuột vào nút Play thì trò chơi của bạn sẽ bắt đầu.


## 3) Các thành phần trong game
- Ếch Hunter: là nhân vật chính trong game, Hunter sẽ luôn chạy còn bạn thì phải điều khiển hoạt động của Hunter để tránh các chướng ngại vật có trên đường.
- Quái (chướng ngại vật): Chúng sẽ xuất hiện random trên đường.
- Quả (hồi máu): Quả cũng sẽ xuất hiện random trên trời.
- Đá: Chiều cao của đá lớn hơn độ cao mà mỗi lần Hunter nhảy, do đó Hunter không thể nhảy qua đá mà phải bắn ra tia laze để phá hủy đá, nếu đá không kịp phá hủy trước khi Hunter chạm vào nó thì Game sẽ kết thúc.
- Tia laze: Tia laze được bắn ra sẽ phá hủy được đá.
- Thanh máu: Cho biết sinh mạng của Hunter còn lại bao nhiêu.
- Điểm số hiện tại và điểm cao nhất: Dòng bên trên sẽ cho bạn biết điểm hiện tại của bạn còn dòng bên dưới sẽ cho bạn biết điểm cao nhất mà bạn từng đạt được.
- Nút tạm dừng/Tiếp tục: Khi bạn nhấn tạm dừng thì nút sẽ chuyển sang dạng , còn khi bạn nhấn tiếp tục thì nút chuyển sang dạng .
- Bố cục game cơ bản:

## 4) Cách chơi
- Đối với Menu:
  + Dùng chuột để tương tác với Menu.
  + Mũi tên sang trái trên bàn phím để Tạm dừng game.
  + Mũi tên sang phải trên bàn phím để Tiếp tục chơi.
  + Khi hết máu hoặc va phải đá: Nhấn nút SPACE (nút cách) trên bàn phím để chơi lại hoặc nhấn nút ESC trên bàn phím để thoát game.
- Đối với nhân vật:
  + Sử dụng Mũi tên lên trên trên bàn phím để Hunter nhảy.
  + Sử dụng nút A để Hunter bắn Laze.
### a) Chức năng của các đối tượng trong game
|      | Tên đối tượng | Chức năng |
|------|---------------|-----------|
|      | Quái | Va phải Quái sẽ làm giảm máu của Hunter |
|      | Quả  | Ăn quả thì Hunter sẽ hồi máu            |
|      | Đá   | Va phải đá Game sẽ kết thúc             |
|      | Laze | Phá hủy Đá                              |

## 5) Kết thúc Game
- Game sẽ kết thúc khi Thanh Máu chuyển thành màu đen hoặc Hunter va phải đá.
- Bạn sẽ có 2 sự lựa chọn:
  + Sử dụng nút SPACE (nút cách) : để chơi lại.
  + Sử dụng nút ESC : để thoát game.
## 6) Các tính năng của Hunter Game
- Menu game.
- Nhạc nền và hiệu ứng âm thanh.
- Tính điểm và lưu lại điểm cao nhất ngay cả khi tắt Game.
- Khi kết thúc 1 lần chơi, có sự lựa chọn chơi lại hoặc không.
## 7) Hướng phát triển về sau
- Làm tốc độ chạy tăng dần qua các mốc thời gian.
- Phát triển cho 2 người chơi với nhau.
- Xây dựng thêm Quái với tính năng mới như : Có thể bắn ra đạn,...

## Source Code Game
- Code tham khảo: https://github.com/quanxuantruong/DINO-RUN?fbclid=IwZXh0bgNhZW0CMTAAAR2RZ4G3t0LctkpDuwwhnr7fadLHYOQhejXOnMISBRgguzea9CkyUG8-Tg8_aem_ATmcW8fKl-8UDG-wJKJJccJJ6zblioC_r5xgzQ2Db2bDGx0Iziwh1r2_Fq-AhyqVpP0oAzkDrwUn_Wwmf1JHjTxH

- Func ( .h, .cpp) : Chứa tất cả các thông số, định nghĩa tổng.
- BaseObject ( .h, .cpp) : Chứa các hàm định nghĩa việc tạo kết cấu, Load ảnh và vẽ lên Window.
- TienIch ( .h, .cpp) : Chứa các hàm định nghĩa việc tạo các đối tượng, kiểm tra va chạm, xử lí sự kiện các nút, vẽ chữ lên màn...
- main.cpp : liên kết các file, tạo logic chính cho game.
- Ech ( .h, .cpp) : Các tác vụ với nhân vật bao gồm: Tạo kết cấu, Load ảnh, bắt sự kiện...
- Botton ( .h, .cpp) : Các tác vụ với các nút chức năng game: Tạo kết cấu, load ảnh, bắt sự kiện...
- Bullet ( .h, .cpp) : Các tác vụ với tia Laze.
- Da ( .h, .cpp) : Các tác vụ với Đá.
- HoiMau ( .h, .cpp) : Các tác vụ với Quả.
- KeThu ( .h, .cpp) : Các tác vụ với Quái.
- Max.txt : Ghi/Đọc điểm cao nhất.
- ThanhMau ( .h, .cpp) : Các tác vụ với Thanh Máu.

## Nguồn ảnh/icon
- Pinterest.
- Canva.
