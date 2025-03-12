

alias dtp='cd ~/Desktop/42home/pipex'
alias dtf='cd ~/Desktop/42home/'
alias dte='cd ~/Desktop/42home/exam-shell-modified'
alias dt='cd ~/Desktop/'
alias mcc='cc -Wall -Wextra -Werror'
alias gitapdeep='cd ~/Desktop/42home && gitap "root directory updated"'

gitac() {
    git add --all
    git commit -m "$1"
}

gitap() {
    git add --all
    git commit -m "$(basename $(pwd)) $(date +'%Y-%m-%d %H:%M:%S')"
    git push
}

USER=mtripodi
MAIL=mtripodi@student.42adel.o

export USER
export MAIL

export PATH="$PATH:/home/matthew/.local/bin"
