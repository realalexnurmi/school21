osascript -e 'tell application "Finder" to set desktop picture to POSIX file "/Users/enena/Pictures/wallpapper.png"'

mkdir -p ~/goinfre/docker
rm -rf ~/Library/Containers/com.docker.docker
ln -s ~/goinfre/docker ~/Library/Containers/com.docker.docker

rm -rf ~/Library/Caches
mkdir ~/Library/Caches
rm -rf ~/.Trash
mkdir ~/.Trash
rm -rf ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage
mkdir ~/Library/Application\ Support/Slack/Service\ Worker/CacheStorage

alias sth='MY_HOME=$(cat ~/.home_path)'
sth
function cd(){
	if [ -n "$1" ]
	then
		builtin cd "$1"
	else
		builtin cd
	fi
	pwd > ~/.home_path
}
function gitall(){
	git add .
	if [ -n "$1" ]
	then
		git commit -m "$1"
	else
		git commit -m "Update this and no comment commit"
	fi
	git push
}
alias gh='cd $MY_HOME'
alias cl='clear && clear && clear && clear'
alias bb="osascript -e 'tell application \"System Events\" to log out '"
#HOUR=$(date +%H)
#case HOUR in
#	)
#		Message="Доброго утра,"
#		;;
#esac
#say -v Milena $Message "повелитель, рада видеть Вас снова!"
gh

# Load Homebrew config script
source $HOME/.brewconfig.zsh
