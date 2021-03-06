 #!/usr/bin/bash
 cd src_proj

 clear
 echo "Utilisez les touches du clavier pour presser les boutons."
 echo "Les touches z q s d pour diriger,"
 echo "les touches a et p pour agiter et presser"
 while true; do
    echo "Entrez une touche: "
    read -n 1 touche
    case "$touche" in
        'z') 
            touch up.txt
            echo ": pressing up..."
            sleep 2
            rm up.txt
            ;;
        'q')
            touch left.txt
            echo ": pressing left..."
            sleep 2
            rm left.txt
            ;;
        's')
            touch down.txt
            echo ": pressing down..."
            sleep 2
            rm down.txt
            ;;
        'd')
            touch right.txt
            echo ": pressing right..."
            sleep 2
            rm right.txt
            ;;
        'p')
            touch on.txt
            echo ": pushing..."
            sleep 2
            rm on.txt
            ;;
        'a')
            touch agiter.txt
            echo ": shaking..."
            sleep 2
            rm agiter.txt
            ;;
    esac
done
