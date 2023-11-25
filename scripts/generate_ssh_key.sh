path_to_key=~/.ssh/honeycombsystem_honeybadger
algorithm=ed25519
comment=miekickimateusz+honeycombsystem@gmail.com

ssh-keygen -t $algorithm -f $path_to_key -C $comment

echo "Public key:"
cat $path_to_key.pub

echo "Do you want to print private key? [y/n]"
read -r answer
if [ "$answer" != "${answer#[Yy]}" ] ;then
    cat $path_to_key
fi