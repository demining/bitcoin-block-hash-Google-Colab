head -c80|sha256sum|xxd -r -p|sha256sum|rev|tail -c65|dd conv=swab
