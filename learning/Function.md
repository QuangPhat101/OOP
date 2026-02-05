- Tạo 1 lần nhiều file
$classes = "Account", "BankAccount", "StockAccount", "CryptoAccount", "User", "NormalUser", "VIPUser"
foreach ($class in $classes) {
    $upper = $class.ToUpper()
    $content = "#ifndef ${upper}_H`n#define ${upper}_H`n`nclass $class {`npublic:`n};`n`n#endif"
    Set-Content -Path "$class.h" -Value $content
    New-Item -Path "$class.cpp" -ItemType File
}
- Tất cả các hàm .h include các thư viện, còn .cpp thì chỉ include .h
- Hàm main chỉ vài dòng, ko định nghĩa cái gì, có nhiêu thì đưa vào usecase
- Tĩnh thực chất là toàn cục (hàm, biến static)
- unit test gồm: hàm, lớp, usecase

